#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL3wuFplfUM"
#define BLYNK_TEMPLATE_NAME "Smart Health Monitoring"
#define BLYNK_AUTH_TOKEN "lbU7PZbALcOc0UTe5NT2jKIKE_erisxm"

#include <ESP8266WiFi.h>
#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#include <math.h>

// Blynk authentication token
char auth[] = BLYNK_AUTH_TOKEN;

// WiFi credentials
char ssid[] = "Hello qw"; // Your Wi-Fi SSID
char pass[] = "123456789"; // Your Wi-Fi password

// Define ECG sensor pin
const int ecgPin = A0; // ECG sensor analog output to A0

// Define heart pulse sensor pin
const int pulsePin = D4; // Heart pulse sensor analog output to D4

// Initialize MLX90614 temperature sensor
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

// Threshold values for alerts
const float TEMP_THRESHOLD_HIGH = 37.5;
const int ECG_THRESHOLD_LOW = 500; // Adjust as per your sensor's range
const int ECG_THRESHOLD_HIGH = 1500; // Adjust as per your sensor's range
const int PULSE_THRESHOLD_LOW = 60;
const int PULSE_THRESHOLD_HIGH = 100;

// Timer
SimpleTimer timer;

// Variables for pulse detection
unsigned long lastPulseTime = 0;
unsigned long currentTime = 0;
unsigned long interval = 0;
const int maxIntervals = 10;
unsigned long intervals[maxIntervals];
int intervalIndex = 0;

// Function to calculate HRV (RMSSD)
float calculateHRV() {
  unsigned long sumOfSquares = 0;
  int count = 0;
  for (int i = 1; i < maxIntervals; i++) {
    if (intervals[i] != 0 && intervals[i-1] != 0) {
      long diff = intervals[i] - intervals[i-1];
      sumOfSquares += diff * diff;
      count++;
    }
  }
  if (count > 0) {
    return sqrt(sumOfSquares / count);
  } else {
    return 0;
  }
}

void detectPulse() {
  int pulseValue = analogRead(pulsePin);

  // Detect pulse peak
  if (pulseValue > 512) { // Adjust threshold as needed
    currentTime = millis();
    interval = currentTime - lastPulseTime;
    lastPulseTime = currentTime;

    // Store interval
    intervals[intervalIndex] = interval;
    intervalIndex = (intervalIndex + 1) % maxIntervals;

    // Calculate HRV
    float hrv = calculateHRV();
    Serial.print("HRV: ");
    Serial.println(hrv);

    // Send HRV value to Blynk (to V4)
    Blynk.virtualWrite(V4, hrv);
  }
}

void notifyOnHealthAlert() {
  // Read object temperature from MLX90614 sensor
  float objTemp = mlx.readObjectTempC();
  Serial.print("Object Temperature: ");
  Serial.println(objTemp);

  // Send temperature value to Blynk
  Blynk.virtualWrite(V0, objTemp);

  // Check temperature threshold
  if (objTemp > TEMP_THRESHOLD_HIGH) {
    Blynk.logEvent("health_alert", "Emergency: High temperature detected!");
  }

  // Read ECG sensor value
  int ecgValue = analogRead(ecgPin);
  Serial.print("ECG Value: ");
  Serial.println(ecgValue);

  // Send ECG value to Blynk (to V1)
  Blynk.virtualWrite(V1, ecgValue);

  // Check ECG thresholds
  if (ecgValue < ECG_THRESHOLD_LOW || ecgValue > ECG_THRESHOLD_HIGH) {
    Blynk.logEvent("health_alert", "Emergency: Abnormal ECG reading detected!");
  }

  // Read heart pulse sensor value
  int pulseValue = analogRead(pulsePin);
  pulseValue = pulseValue / 10;

  Serial.print("Heart Pulse Value: ");
  Serial.println(pulseValue);

  // Send divided heart pulse value to Blynk (to V2)
  Blynk.virtualWrite(V2, pulseValue);

  // Calculate Sleep Score
  float SleepScore = 0.2 * objTemp + 0.5 * pulseValue + 0.2 * ecgValue;

  // Normalize Sleep Score to a range of 0 to 100
  SleepScore = constrain(SleepScore, 0, 100);

  Serial.print("Sleep Score: ");
  Serial.println(SleepScore);

  // Send Sleep Score value to Blynk (to V3)
  Blynk.virtualWrite(V3, SleepScore);

  // Check heart pulse thresholds
  if (pulseValue < PULSE_THRESHOLD_LOW || pulseValue > PULSE_THRESHOLD_HIGH) {
    Blynk.logEvent("health_alert", "Emergency: Abnormal heart pulse detected!");
  }

  // Calculate HRV and send to Blynk (to V4)
  detectPulse();
}

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Initialize Blynk
  Blynk.begin(auth, ssid, pass);

  // Sync virtual pin V3 with server
  Blynk.syncVirtual(V3);

  // Initialize I2C communication for MLX90614
  Wire.begin(D3, D2); // SDA on D3 (GPIO0), SCL on D2 (GPIO4)
  mlx.begin();

  // Set a timer to call notifyOnHealthAlert every 2 seconds
  timer.setInterval(2000L, notifyOnHealthAlert);
}

void loop() {
  // Run Blynk
  Blynk.run();

  // Run the timer
  timer.run();
}