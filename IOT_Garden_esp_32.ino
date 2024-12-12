// Define Blynk Template ID and Template Name
#define BLYNK_TEMPLATE_ID "TMPL37jakfh57"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "oeUoh0BDkpzqtnuoRK-E_0bb6YI6J4Le"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

const int relayPin = 33;           // Relay pin (valid GPIO)
const int moistureSensorPin = 32;  // Soil moisture sensor pin (ADC-capable)

int moistureLevel;  // Variable to store moisture level

BlynkTimer timer;

char auth[] = BLYNK_AUTH_TOKEN;  // Blynk auth token
char ssid[] = "Galaxy M14 5G 22CF";  // WiFi SSID
char pass[] = "akshatlakum";         // WiFi password

// Function to read soil moisture sensor and control relay
void sendSoilData() {
  // Read raw analog value from the moisture sensor
  int rawValue = analogRead(moistureSensorPin);

  // Map the raw sensor value (0-4095 for ESP32) to a percentage (0-100%)
  moistureLevel = map(rawValue, 0, 4095, 0, 100);

  // Print the raw and mapped moisture levels to Serial Monitor for debugging
  Serial.print("Raw Moisture Sensor Value: ");
  Serial.print(rawValue);
  Serial.print(" | Mapped Soil Moisture Level: ");
  Serial.print(moistureLevel);
  Serial.println("%");

  // Send moisture level to Blynk virtual pin V5
  Blynk.virtualWrite(V5, moistureLevel);

  // Control relay based on moisture level (e.g., if dry, activate relay to water plants)
  if (moistureLevel < 30) {  // Example threshold; adjust as needed
    digitalWrite(relayPin, HIGH);  // Turn on relay
    Serial.println("Relay ON - Watering the plants");
  } else {
    digitalWrite(relayPin, LOW);   // Turn off relay
    Serial.println("Relay OFF - Soil moisture sufficient");
  }
}

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);  // Ensure baud rate matches Serial Monitor
  delay(1000);  // Give time for Serial to initialize

  Serial.println("Initializing...");

  // Set ADC resolution
  analogReadResolution(12);  // ESP32 default resolution (12 bits, 0-4095)

  // Initialize relay pin as output and set it to LOW initially
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);  // Ensure relay is off at startup

  // Attempt to connect to WiFi
  Serial.print("Connecting to WiFi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);

  unsigned long startAttemptTime = millis();

  // Attempt to connect to WiFi for 10 seconds
  while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < 10000) {
    Serial.print(".");
    delay(500);
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWiFi connected!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
    Blynk.begin(auth, ssid, pass);  // Initialize Blynk only if WiFi is connected
  } else {
    Serial.println("\nFailed to connect to WiFi! Check credentials.");
  }

  // Set up a timer to call sendSoilData function every 5 seconds
  timer.setInterval(5000L, sendSoilData);  // Call sendSoilData every 5 seconds
}

void loop() {
  // Run Blynk and timer
  Blynk.run();
  timer.run();
}
