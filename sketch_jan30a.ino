#include <LiquidCrystal.h>

// RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int tempPin = A0;

// ===== SIMBOLO GRADO =====
byte grado[8] = {
  B00111,
  B00101,
  B00111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

// ===== BARRE VERTICALI (0-8) =====
byte bar0[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00000};
byte bar1[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B11111};
byte bar2[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B11111,B11111};
byte bar3[8] = {B00000,B00000,B00000,B00000,B00000,B11111,B11111,B11111};
byte bar4[8] = {B00000,B00000,B00000,B00000,B11111,B11111,B11111,B11111};
byte bar5[8] = {B00000,B00000,B00000,B11111,B11111,B11111,B11111,B11111};
byte bar6[8] = {B00000,B00000,B11111,B11111,B11111,B11111,B11111,B11111};
byte bar7[8] = {B00000,B11111,B11111,B11111,B11111,B11111,B11111,B11111};
byte bar8[8] = {B11111,B11111,B11111,B11111,B11111,B11111,B11111,B11111};

float tempMin = 100;
float tempMax = -50;

void setup() {
  lcd.begin(16, 2);

  lcd.createChar(0, grado);
  lcd.createChar(1, bar0);
  lcd.createChar(2, bar1);
  lcd.createChar(3, bar2);
  lcd.createChar(4, bar3);
  lcd.createChar(5, bar4);
  lcd.createChar(6, bar5);
  lcd.createChar(7, bar6);
  // bar7 e bar8 non servono entrambi per limiti LCD

  // ===== MESSAGGIO INIZIALE =====
  lcd.setCursor(0, 0);
  lcd.print("Ciao Gheris!");
  lcd.setCursor(0, 1);
  lcd.print("Avvio sistema");
  delay(2000);
  lcd.clear();
}

void loop() {
  int valore = analogRead(tempPin);
  float tensione = valore * (5.0 / 1023.0);
  float temperatura = (tensione - 0.5) * 100.0; // TMP36

  // Limiti
  if (temperatura < 0) temperatura = 0;
  if (temperatura > 40) temperatura = 40;

  // Min / Max
  if (temperatura < tempMin) tempMin = temperatura;
  if (temperatura > tempMax) tempMax = temperatura;

  // ===== MAPPATURA BARRA (0–8) =====
  int livello = map(temperatura, 0, 40, 0, 8);

  // ===== RIGA 1 =====
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperatura, 1);
  lcd.write(byte(0));
  lcd.print(" ");

  lcd.print("M:");
  lcd.print(tempMin, 0);
  lcd.print("/");
  lcd.print(tempMax, 0);

  // ===== RIGA 2 =====
  lcd.setCursor(0, 1);
  lcd.print("Barra temp ");

  // Barra verticale (ultima colonna)
  lcd.setCursor(15, 1);
  lcd.write(livello + 1);  // carattere custom

  delay(1000);
}
