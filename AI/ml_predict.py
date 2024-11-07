import streamlit as st
import pandas as pd
import numpy as np
from sklearn.preprocessing import StandardScaler
from xgboost import XGBRegressor
from sklearn.model_selection import train_test_split, GridSearchCV
from sklearn.metrics import mean_squared_error, r2_score
import matplotlib.pyplot as plt
import seaborn as sns

# Function to load and preprocess data
def load_and_preprocess_data(filepath):
    data = pd.read_csv(filepath)
    data['Datetime'] = pd.to_datetime(data['Date'] + ' ' + data['Time'])
    data = data.drop(columns=['Date', 'Time'])
    data = data.dropna()
    return data

# Function for feature engineering
def perform_feature_engineering(data):
    data['temperature_rolling'] = data['temperature'].rolling(window=3).mean()
    data['ecg_diff'] = data['ecg'].diff()
    data = data.dropna()
    return data

# Function for model training and evaluation
def train_and_evaluate_model(X_train, y_train, X_test, y_test):
    xgb_model = XGBRegressor(eval_metric='rmse')
    param_grid = {
        'n_estimators': [100, 200, 300],
        'learning_rate': [0.01, 0.1, 0.2],
        'max_depth': [3, 5, 7]
    }
    grid_search = GridSearchCV(estimator=xgb_model, param_grid=param_grid, cv=3, n_jobs=-1, verbose=2)
    grid_search.fit(X_train, y_train)

    best_xgb = grid_search.best_estimator_
    y_pred = best_xgb.predict(X_test)

    st.write("XGBoost Best Parameters:", grid_search.best_params_)
    st.write("XGBoost Mean Squared Error:", mean_squared_error(y_test, y_pred))
    st.write("XGBoost R^2 Score:", r2_score(y_test, y_pred))

    return best_xgb

# Load and preprocess the data
data = load_and_preprocess_data('MediSync Data.csv')
data = perform_feature_engineering(data)

# Feature scaling
scaler = StandardScaler()
features = ['temperature', 'ecg', 'pulse', 'temperature_rolling', 'ecg_diff']
X = data[features]
y = data['sleepscore']
X = scaler.fit_transform(X)

# Train-test split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42)

# Train and evaluate model
best_xgb = train_and_evaluate_model(X_train, y_train, X_test, y_test)

# Example current data (for real-time prediction)
current_temperature = 36.5  # Replace with your current temperature
current_ecg = 0.8           # Replace with your current ECG value
current_pulse = 72          # Replace with your current pulse rate
current_temperature_rolling = 36.5  # Replace with your calculated rolling temperature
current_ecg_diff = 0.1      # Replace with your calculated ECG difference

# Create DataFrame for current data
current_data = pd.DataFrame({
    'temperature': [current_temperature],
    'ecg': [current_ecg],
    'pulse': [current_pulse],
    'temperature_rolling': [current_temperature_rolling],
    'ecg_diff': [current_ecg_diff]
})

# Apply the same feature scaling
current_data_scaled = scaler.transform(current_data)

# Predict health score
predicted_score = best_xgb.predict(current_data_scaled)[0]

# Display results in Streamlit
st.title('Health Prediction Results')
st.write(f"Predicted Health Score: {predicted_score}")

# Visualization (optional): Feature importances
st.subheader('Feature Importances')
features_importance = best_xgb.feature_importances_
fig, ax = plt.subplots()
sns.barplot(x=features, y=features_importance, palette='viridis', ax=ax)
st.pyplot(fig)

# Visualization (optional): Prediction vs Actual
st.subheader('Prediction vs Actual')
y_pred = best_xgb.predict(X_test)
fig, ax = plt.subplots()
ax.scatter(y_test, y_pred, alpha=0.5)
ax.plot([min(y_test), max(y_test)], [min(y_test), max(y_test)], color='red', linestyle='--')
ax.set_xlabel('Actual Sleepscore')
ax.set_ylabel('Predicted Sleepscore')
st.pyplot(fig)
