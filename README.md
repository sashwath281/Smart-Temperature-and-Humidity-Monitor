# Smart Temperature and Humidity Monitor using Arduino Uno

This project displays temperature and humidity on a 16x2 LCD using a DHT11 sensor, and triggers a buzzer through a relay when the temperature exceeds 24°C.

---

## Components Used
- Arduino Uno
- DHT11 Temperature & Humidity Sensor
- 16x2 LCD Display with I2C module
- Relay Module
- Buzzer
- Potentiometer
- Breadboard & jumper wires

---

## Project Photos
| Code Running | Sensor Close-up |
|--------------|-----------------|
| ![code](code%20photo.jpg) | ![sensor](photo%20of%20dht11.jpg) |

| LCD With Buzzer ON |
|--------------------|
| ![on](screen%20view.jpg) |

| Top View |
|----------|
| ![top](top%20view.jpg) |

---

## How It Works
1. Reads temperature & humidity from DHT11 sensor.
2. Displays readings on LCD.
3. If temperature > 30°C, relay turns on buzzer.
4. Delay of 3 seconds before next reading.

---

## Run the Code
Upload the `.ino` file to your Arduino Uno using the Arduino IDE.

---

## 📁 Files
- `SmartTempMonitor.ino` - Arduino code
- `README.md` - This project explanation
- 5 photos for documentation
