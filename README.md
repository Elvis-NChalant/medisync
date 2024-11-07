# MediSync: Smart Health Monitoring System for Elderly Care with Medication Reminder
## Introduction
<p align = "justify">
As the global population ages, the need for efficient and effective elderly care solutions becomes increasingly vital. The elderly often face complex health challenges that require constant monitoring and timely medication management. Traditional care methods, while essential, can be insufficient in addressing these needs comprehensively.

Elderly individuals are often affected by chronic diseases such as diabetes, hypertension, and heart conditions. Continuous monitoring of these conditions is crucial to prevent complications and manage health effectively. Proper medication management is a significant challenge among the elderly. Forgetting to take prescribed medications or taking incorrect doses can lead to serious health risks. 

### Abstract
MediSync is an innovative smart health monitoring system designed to address the growing need for effective elderly care solutions. As the global population ages, managing chronic diseases and ensuring proper medication adherence become critical challenges. MediSync leverages advanced IoT sensors and AI algorithms to provide continuous, real-time monitoring of vital signs such as heart rate, oxygen saturation, and body temperature. The system features a user-friendly interface and a mobile application for medication reminders, personalized health insights, and emergency alerts. By integrating wearable devices and a robust communication platform, MediSync empowers elderly individuals and their caregivers with timely, actionable health data, ultimately enhancing the quality of care and promoting independent living.

## Overview
<p align = "justify">
MediSync is a smart health monitoring system specifically designed to cater to the unique requirements of elderly individuals. It leverages advanced technology to provide continuous health monitoring, ensuring that vital signs and health parameters are tracked in real-time. This system not only helps in detecting potential health issues early but also aids caregivers in making informed decisions promptly.
It integrates IoT sensors and wearable devices to continuously monitor vital signs such as heart rate and oxygen saturation.. This data is transmitted to a server where algorithms analyze trends and detect anomalies in health metrics. The system includes a mobile application that provides medication reminders, personalized health insights, and alerts to caregivers or healthcare providers in case of emergencies.

The project showcased here introduces an innovative solution utilising several health sensors to continously monitor patient vitals.
<ul>
<li><b>Pulse Oximeter (MAX30100)</b>: Measures the saturation of oxygen carried in your red blood cells.</li>
<li><b>Body Temperature Sensor (MLX90614)</b>: Enables measurement of body temperature to detect fever.</li>
<li><b>ESP8266 WIFI module</b>: Enables connection transmission of sensor data to the cloud using Wifi.</li>
</ul>

![Brochure](https://github.com/Prabu1717/MediSync-Smart-Health-Monitoring-System/blob/main/Assets/Brochure.png)

## Bill of Materials

| Item                        | Quantity | Description                                      | Links to Products for reference                                                   | Cost               |
|-----------------------------|----------|--------------------------------------------------|----------------------------------------------------------------------------------|--------------|
|                  | |                             |          |                                     
| NodeMCUESP8266                     | 1        | WiFi Module for communication                    | [ESP8266](https://www.google.com/aclk?sa=l&ai=DChcSEwjN4NLgoYCHAxXSMIMDHdFYCXkYABARGgJzZg&ase=2&gclid=CjwKCAjw4f6zBhBVEiwATEHFVuPedc9bTqo8eR-5Y3V9Te39JrnE6BA_qY9L-74SgrdNaetIzO5nBxoChXIQAvD_BwE&sig=AOD64_0Wz3XH7RxaOpz7t6T6M3WHv2fdSg&ctype=5&q=&nis=4&ved=2ahUKEwiPr83goYCHAxV93TgGHWYFCRYQ9aACKAB6BAgFEBI&adurl=)       | 150|
| MLX90614 Infrared Temperature Sensor | 1        | Sensor for measuring object temperature          | [MLX90614 ESF](https://www.google.com/aclk?sa=l&ai=DChcSEwjcwuqiqYCHAxV5pGYCHVZMAqIYABAFGgJzbQ&ase=2&gclid=CjwKCAjw4f6zBhBVEiwATEHFVjAZLOWoIncrbvtZTWRzqYTtrKSwG7UURQrY221X3hsmSMUHCdamqxoCbTgQAvD_BwE&sig=AOD64_0hwd6BrUy7pgiUvmWbOgsinpd3UQ&ctype=5&q=&nis=4&ved=2ahUKEwjvoOSiqYCHAxUO1TgGHTWnDSYQ9aACKAB6BAgBECk&adurl=)        | 800
| I2C LCD Display (16x2)      | 1        | Display for showing sensor readings              | [LCD Display](https://www.google.com/shopping/product/2542292417593159478?sca_esv=6e16df18d91a5be0&rlz=1C1RXQR_enIN956IN956&q=LCD+display&fbs=AEQNm0DPvcmG_nCbmwtBO9j6YBzM68ZanC7g01Skprhw5JoufVCiMv-hxC44jt6JduRQysBab-bgQXjPraaWFXMvOy8Kr1OAG3K-aj3De4zf3-LxKtkBtWaSCp743evHzhY6J0rIQUCXki65vOxhV0cGJtj0S1dF8YREnKrWtJctBkTv8-bs83YpB7p3IMTdYvjisDEty1xSxeLS4B_TKFXUiCrenmEMcA&ictx=111&biw=1536&bih=695&dpr=1.25&prds=eto:5770357066547990025_0,pid:12519735675801120477&sa=X&ved=0ahUKEwjBh8DyqYCHAxXNka8BHa4kJhoQ8wIIyQg)           | 190 |
| Jumper Wires                | 1        | Wires for connecting components                 | [Jumper Wires](https://www.amazon.in/Jumper-Female-breadboard-jumper-Cable/dp/B0B4SNVKHB)                                                                           | 100|
| HW 827 Pulse Sensor         | 1        | Sensor for measuring pulse rate                 | [HW 827 Pulse Sensor](https://www.amazon.in/Robodo-Electronics-PLSNSR1-Arduino-Raspberry/dp/B07B8KHYC8/ref=sr_1_1?s=industrial&sr=1-1)                                                                            | 270 |
| GSM 800L                    | 1        | GSM module for cellular communication           | [GSM 800L](https://www.amazon.in/RoboElectrixX-GPRS-SIM800L-Module-antenna/dp/B07VDV8HHG/ref=sr_1_4?sr=8-4)                                                                         | 500|
| AD 8232 ECG Sensor          | 1        | Sensor for measuring ECG signals                | [AD 8232 ECG Sensor ](https://www.amazon.in/Robodo-Electronics-AD8232-Measurement-Monitoring/dp/B07B8YRMYJ/ref=sr_1_3?sr=8-3)                                                                           | 750|
| HW 691 Temperature Sensor   | 1        | Sensor for measuring temperature                | [HW 691](https://robocraze.com/products/mlx90614esf-infrared-ir-temperature-sensor-module?currency=INR&variant=40193078067353&stkn=c03aaf8845ec&campaignid=21235107347&adgroupid=&keyword=&device=c&gad_source=1)                                                                          | 780|
| Zero PCB board              | 1        | Printed circuit board for mounting components   | [Zero PCB board  ](https://www.electronicscomp.com/general-purpose-perforated-pcb-6x4inches?gad_source=1)                                                          |50                  |
| Cables                      | 1        | Various cables for connections                   |[Cables](https://www.amazon.in/Techno-Parts-PULLER-ALLOY-CABLE/dp/B0CHW6GBGZ/ref=sr_1_4?s=home-improvement&sr=1-4)                                                                            | 250|
| 3.7V Li-ion Cell                      | 1        | Cell used to power GSM Module                   |[Battery](https://www.flipkart.com/smuf-18650-li-ion-cell-3-7v-1200mah-4-4wh-rechargeable-lithium-solar-battery/p/itm3a54cf1421872?pid=SBYGHXTZQVEYMEWE&lid=LSTSBYGHXTZQVEYMEWE54REAN&marketplace=FLIPKART&cmpid=content_solar-battery_8965229628_gmc)                                                                            | 250|

### Notes:
- **MLX90614 Infrared Temperature Sensor**: This sensor enables precise non-contact measurement of object temperature, essential for applications like fever detection in health monitoring systems.
- **AD 8232 ECG Sensor**: The ECG sensor captures and processes the electrical activity of the heart, providing critical insights into cardiac health, making it invaluable for continuous heart monitoring in medical devices. 
- **NodeMCU ESP8266 Wi-Fi Module**: The WiFi module facilitates wireless communication, allowing seamless transmission of sensor data to cloud-based platforms or remote servers, enabling real-time monitoring and analysis over the internet.
- **HW 827 Pulse Sensor**: Sensor used to measure pulse rate of the individual.
- **GSM 800L**: This GSM module enables cellular communication, making it suitable for applications where internet connectivity via WiFi is limited or unavailable, ensuring reliable data transmission in remote or mobile environments.

## Connections

| Component             | Pin on Component | Pin on NodeMCU ESP8266 | Description                                            |
|-----------------------|------------------|------------------------|--------------------------------------------------------|
| **AD8232 ECG**        | GND              | GND                    | Ground connection                                      |
|                       | 3.3V             | 3V3                    | Power supply                                           |
|                       | OP               | A0                     | Output signal to read ECG data                         |
|                       | LO-              | GND                    | Lead-off detection (negative)                          |
|                       | LO+              | N/A                    | Lead-off detection (positive)                          |
|                       | SDN              | N/A                    | Shutdown control (not connected)                       |
| **HW 691 Infra Temp** | SDA              | D3 (SDA)               | I2C data line for communication                        |
|                       | SCL              | D2 (SCL)               | I2C clock line for communication                       |
|                       | GND              | GND                    | Ground connection                                      |
|                       | VIN              | 3V3                    | Power supply                                           |
| **HW 827 Heart Rate** | VCC              | 3V3                    | Power supply                                           |
|                       | GND              | GND                    | Ground connection                                      |
|                       | D/O               | D4                     | Digital output for heart rate data                     |
| **GSM SIM800L**       | VCC              | +4.4V (External)       | Power supply                                           |
|                       | GND              | GND                    | Ground connection                                      |
|                       | TXD              | D1                     | Transmit data line (TX)                                |
|                       | RXD              | D0                     | Receive data line (RX)                                 |


## Interfacing Diagram
![Final NodeMCU Circuit](https://github.com/Prabu1717/MediSync-Smart-Health-Monitoring-System/blob/main/Assets/Final%20nodemcu%20circ.jpeg)

## Finished Product
![Smart Health Product](https://github.com/Prabu1717/MediSync-Smart-Health-Monitoring-System/blob/main/Assets/smart%20health%20prod.jpeg)

![image](https://github.com/Prabu1717/MediSync-Smart-Health-Monitoring-System/blob/main/Assets/shzeropcb.jpeg)

## Objectives
<ul>
<li><b>Real-Time Health Monitoring: </b> Enable real-time monitoring of vital signs for prompt health anomaly detection.</li>
<li><b>Medication Management:</b>Provide medication management through reminders and tracking.</li>
<li><b>Remote Caregiver Access:</b> Facilitate remote access to health data and alerts for caregivers </li>
<li><b>Promote Independence:</b>Empower elderly individuals to maintain independence with self-care technologies.</li>
<li><b>Efficiency in Healthcare:</b>Improve healthcare efficiency by reducing unnecessary hospital visits.</li>
</ul>

## Components
- MLX90614 Infrared Temperature Sensor
- I2C LCD Display (16x2)
- Jumper wires
- NodeMCU ESP 8266
- HW 827 Pulse
- GSM 800L
- AD 8232 ECG
- HW 691 Temperature
- Zero PCB Board
- Cables

## Libraries
- Adafruit MLX90614 Library
- LiquidCrystal I2C Library
- ESP8266WiFi.h
- Wire.h
- BlynkSimpleEsp8266.h

## Code

```cpp
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
```
## Dashboard
![image](https://github.com/Prabu1717/MediSync-Smart-Health-Monitoring-System/blob/main/Assets/medisync_dashboard.png)

![image](https://github.com/Prabu1717/MediSync-Smart-Health-Monitoring-System/blob/main/Assets/analytics.jpg)


## Video
[MediSync Product Demo](https://drive.google.com/file/d/1KefmGBYEHOlIXaXR9JIy-E3E5xa_ijS1/view?usp=drive_link)

## Presentation
[MediSync Product Pitch Presentation](https://app.presentations.ai/view/BiBjok)

## Conclusion
In summary, MediSync addresses the critical needs of elderly care by integrating smart technology into health monitoring and medication management. This innovative system not only enhances the quality of life for elderly individuals but also provides peace of mind for their caregivers and families. By providing real-time health insights and AI-driven medication management, we empower elderly individuals to maintain their independence while ensuring caregivers have the tools to offer timely support. This solution not only improves health outcomes but also promotes a more efficient and compassionate healthcare system.

