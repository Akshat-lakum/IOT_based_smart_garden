# 🌿 IoT-Based Smart Garden

This project implements a smart irrigation system using an **ESP32 microcontroller** that monitors real-time **soil moisture** and controls watering automatically. The system is integrated with **Blynk IoT** for remote monitoring and control.

---

## 📌 Objective

To develop an IoT-based smart gardening system that ensures optimal soil moisture levels by:
- Continuously monitoring soil conditions
- Automatically activating watering via a relay
- Sending real-time data to the Blynk IoT dashboard

---

## 🧰 Components Used

| Component           | Quantity | Purpose                          |
|--------------------|----------|----------------------------------|
| ESP32              | 1        | Core controller & Wi-Fi module   |
| Breadboard         | 1        | Circuit assembly                 |
| Soil Moisture Sensor | 1      | Reads soil moisture level        |
| Humidity Sensor    | 1        | (Optional) for future expansion  |
| Relay Module       | 1        | Controls the water pump          |
| Jumper Wires       | As needed| Connections                     |
| Soil Container     | 1        | For demo/testing                 |

---

## 🛠️ Circuit Setup

- Connect soil moisture sensor to ESP32 ADC pin (GPIO 32)
- Connect relay module to GPIO 33
- Power the circuit via USB
- Relay turns ON when moisture level drops below threshold (e.g., 30%)

---

## 💻 Code Overview

- **Language**: Arduino C++
- **Platform**: ESP32 + Blynk IoT
- **Libraries Used**:
  - `WiFi.h`
  - `BlynkSimpleEsp32.h`

- **Main Functions**:
  - `analogRead()` to get soil moisture level
  - `map()` to convert raw ADC to % scale
  - `digitalWrite()` to control relay
  - `Blynk.virtualWrite()` to push data to dashboard

---

## 📲 Blynk Integration

- **Template ID**: `TMPL37jakfh57`
- **Template Name**: `Quickstart Template`
- **Auth Token**: (use your Blynk token)

Real-time data is visualized on the Blynk app (V5 virtual pin). You can set alerts or add buttons to manually control irrigation.

---

## 🚀 Getting Started

1. Upload the code to ESP32 via Arduino IDE
2. Replace `ssid`, `pass`, and `auth` with your own Wi-Fi and Blynk credentials
3. Connect ESP32 to your hardware setup
4. Open Serial Monitor to observe readings
5. View real-time moisture data on Blynk app

---

## 📈 Output

- Moisture sensor values printed to Serial Monitor
- Relay automatically turns ON/OFF based on soil dryness
- Moisture level is streamed to Blynk every 5 seconds

---

## 🧪 Testing & Optimization

- Tested under dry and wet soil conditions
- Works reliably for real-time irrigation automation
- Moisture threshold adjustable in code (`< 30`)

---

## 📚 Reference

- Project report: _IoT-Based Smart Garden Monitoring System_
- Dataset / components from local hardware setup
- [Video demo](https://www.youtube.com/watch?v=Ix3a3ThsHfA)

---

## 👨‍💻 Developed By

- **Akshat Lakum** (U22EC040)  
- **Pratham** (U22EC051)  
- **Mit Rohit** (U22CS070)  
Sardar Vallabhbhai National Institute of Technology

---

## 📜 License

This project is open for educational use and can be extended to full-scale irrigation systems.
