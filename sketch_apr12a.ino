#include <LiquidCrystal_I2C.h>
#include <Wire.h>

const int trigPin = 9;
const int echoPin = 10;

// Endereço padrão do LCD I2C (pode ser 0x27 ou 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  lcd.init();               // Inicializa o LCD
  lcd.backlight();          // Liga a luz de fundo
  lcd.setCursor(0, 0);
  lcd.print("Medindo Distancia :)..");
}

void loop() {
  long duration;
  float distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");

  lcd.setCursor(0, 1);
  lcd.print("Dist: ");
  lcd.print(distance, 1); // Mostra com 1 casa decimal
  lcd.print(" cm   ");    // Espaços extras limpam sobras

  delay(500);
}
