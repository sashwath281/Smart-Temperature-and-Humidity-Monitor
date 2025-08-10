#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTPIN 2
#define DHTTYPE DHT11
#define RELAY_PIN 7

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(12, 11, 5, 4, 3, 6);

void printFixed(const char* label, float val, const char* unit, uint8_t col, uint8_t row) {
  lcd.setCursor(col, row);
  lcd.print(label);
  if (isnan(val)) {
    lcd.print("--  ");
  } else {
    int v = (int)round(val);
    if (v < 10) lcd.print(" "); 
    lcd.print(v);
    lcd.print(unit);
  }
}

void setup() {
  lcd.begin(16, 2);
  dht.begin();
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);
  lcd.clear();
  lcd.setCursor(0,0); lcd.print("Temp/Humidity");
}

void loop() {
  float temp = dht.readTemperature();
  float hum  = dht.readHumidity();

  printFixed("T:", temp, "\xDF""C", 0, 1);
  printFixed("  H:", hum, "%",   7, 1);

  bool hot = (!isnan(temp) && temp > 24.0);
  digitalWrite(RELAY_PIN, hot ? LOW : HIGH);

  lcd.setCursor(13, 0);
  lcd.print(hot ? "ON " : "OFF");

  delay(3000);
}
