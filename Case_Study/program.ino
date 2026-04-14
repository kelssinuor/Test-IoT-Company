#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int sensorPin = A0;
int ledMerah = 8;
int ledBiru = 9;
int buzzer = 10;
int button = 7;

void setup() {
  pinMode(ledMerah, OUTPUT);
  pinMode(ledBiru, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT_PULLUP);

  lcd.init();
  lcd.backlight();
}

void loop() {
  int lux = analogRead(sensorPin);

  lcd.setCursor(0, 0);
  lcd.print("LUX: ");
  lcd.print(lux);
  lcd.print("   ");

  if (lux < 500) {
    digitalWrite(ledMerah, HIGH);
    digitalWrite(ledBiru, LOW);
  } else {
    digitalWrite(ledMerah, LOW);
    digitalWrite(ledBiru, HIGH);
  }

  if (digitalRead(button) == LOW && lux > 500) {
    digitalWrite(buzzer, HIGH);
  } else {
    digitalWrite(buzzer, LOW);
  }

  delay(200);
}