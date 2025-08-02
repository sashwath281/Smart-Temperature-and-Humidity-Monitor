#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTPIN 2          // Pin where the DHT11 is connected
#define DHTTYPE DHT11     // Define sensor type
#define RELAY_PIN 7       // Pin connected to relay module

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(12, 11, 5, 4, 3, 6);  // RS, EN, D4, D5, D6, D7

void setup() {
  lcd.begin(16, 2);           // Initialize 16x2 LCD
  dht.begin();                // Initialize DHT sensor
  pinMode(RELAY_PIN, OUTPUT); 
  digitalWrite(RELAY_PIN, HIGH); // Start with buzzer OFF (active-low)
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temp);
  lcd.print((char)223);       // Degree symbol
  lcd.print("C ");

  lcd.setCursor(0, 1);
  lcd.print("H:");
  lcd.print(hum);
  lcd.print("% ");

  // Trigger buzzer via relay (active-low logic)
  lcd.setCursor(10, 1);
  if (temp > 24) {
    digitalWrite(RELAY_PIN, LOW);    // LOW turns buzzer ON
    lcd.print("ON ");
  } else {
    digitalWrite(RELAY_PIN, HIGH);   // HIGH turns buzzer OFF
    lcd.print("OFF");
  }

  delay(3000);  // Wait before next reading
}

