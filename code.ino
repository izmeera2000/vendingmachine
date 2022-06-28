#define BLYNK_TEMPLATE_ID "TMPLvXAW4OOf"
#define BLYNK_DEVICE_NAME "SNACK VENDING MACHINE"
#define BLYNK_AUTH_TOKEN "5-zpjyMvcsbkHfr3ao0RKbMwrN8NqpOo"
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
#define MOTOR1 15
#define MOTOR2 2

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Realme 7i Farid";
char pass[] = "uzumaki suneo";

WidgetLCD virtualLCD(V0);
const byte interruptPin = 23;
int count = 100;
int countreal = 0;
float total = 0.0;
unsigned long Timer = 0;
int timedelay = 6000;
float set1 = 0.50;
float set2 = 0.50;
int stock1 = 10;
int stock2 = 10;
int noty1 = 0;
int noty2 = 0;

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(interruptPin, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(MOTOR1, OUTPUT);
  pinMode(MOTOR2, OUTPUT);
  digitalWrite(MOTOR1, HIGH);
  digitalWrite(MOTOR2, HIGH);
  attachInterrupt(digitalPinToInterrupt(interruptPin), billAcceptor, RISING);
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print(" PLEASE INSERT ");
  lcd.setCursor(0, 1);
  lcd.print("     COIN      ");
  Timer = millis();
  virtualLCD.print(0, 0, "Stock1 :" + String(stock1) + "   ");
  virtualLCD.print(0, 1, "Stock2 :" + String(stock2) + "   ");
}
void loop() {
  Blynk.run();
  Serial.println(count);
  //  if (millis() - Timer > 2000) {
  //    countreal = count - 100;
  //    Serial.println("COUNTREAL:" + String(countreal) + " ");
  //    Timer = millis();
  //  }
  if (countreal == 1) {
    countreal = 0;
    count = 100;
    total = total + 0.10;
    lcd.setCursor(0, 0);
    lcd.print("S1:" + String(set1) + " S2:" + String(set2) + " ");
    lcd.setCursor(0, 1);
    lcd.print("   COIN : " + String(total) + "    ");
  }
  if (countreal == 2) {
    countreal = 0;
    count = 100;
    total = total + 0.20;
    lcd.setCursor(0, 0);
    lcd.print("S1:" + String(set1) + " S2:" + String(set2) + " ");
    lcd.setCursor(0, 1);
    lcd.print("   COIN : " + String(total) + "    ");
  }
  if (countreal == 3) {
    countreal = 0;
    count = 100;
    total = total + 0.50;
    lcd.setCursor(0, 0);
    lcd.print("S1:" + String(set1) + " S2:" + String(set2) + " ");
    lcd.setCursor(0, 1);
    lcd.print("   COIN : " + String(total) + "    ");
  }
  if (countreal == 4) {
    countreal = 0;
    count = 100;
    total = total + 0.10;
    lcd.setCursor(0, 0);
    lcd.print("S1:" + String(set1) + " S2:" + String(set2) + " ");
    lcd.setCursor(0, 1);
    lcd.print("   COIN : " + String(total) + "    ");
  }
  if (countreal == 5) {
    countreal = 0;
    count = 100;
    total = total + 0.20;
    lcd.setCursor(0, 0);
    lcd.print("S1:" + String(set1) + " S2:" + String(set2) + " ");
    lcd.setCursor(0, 1);
    lcd.print("   COIN : " + String(total) + "    ");
  }
  if (countreal == 6) {
    countreal = 0;
    count = 100;
    total = total + 0.50;
    lcd.setCursor(0, 0);
    lcd.print("S1:" + String(set1) + " S2:" + String(set2) + " ");
    lcd.setCursor(0, 1);
    lcd.print("   COIN : " + String(total) + "    ");
  }

  if (total >= set1 && digitalRead(5) == HIGH && stock1 >= 1) {

    total = total - set1;
    stock1--;
    virtualLCD.print(0, 0, "Stock1 : " + String(stock1) + "  ");
    lcd.setCursor(0, 0);
    lcd.print("    SNACK 1    ");
    lcd.setCursor(0, 1);
    lcd.print("   SELECTED    ");
    delay(1000);
    digitalWrite(MOTOR1, LOW);
    delay(timedelay);
    digitalWrite(MOTOR1, HIGH);

    if (total > 0)
    {
      lcd.setCursor(0, 0);
      lcd.print("S1:" + String(set1) + " S2:" + String(set2) + " ");
      lcd.setCursor(0, 1);
      lcd.print("   COIN : " + String(total) + "    ");
    }
    {
      lcd.setCursor(0, 0);
      lcd.print(" PLEASE INSERT ");
      lcd.setCursor(0, 1);
      lcd.print("     COIN      ");
    }
  }

  if (total >= set2 && digitalRead(4) == HIGH && stock2 >= 1) {

    total = total - set2;
    stock2--;
    virtualLCD.print(0, 1, "Stock2 : " + String(stock2) + "  ");
    lcd.setCursor(0, 0);
    lcd.print("    SNACK 2    ");
    lcd.setCursor(0, 1);
    lcd.print("   SELECTED    ");
    delay(1000);
    digitalWrite(MOTOR2, LOW);
    delay(timedelay);
    digitalWrite(MOTOR2, HIGH);
    lcd.setCursor(0, 0);
    lcd.print(" PLEASE INSERT ");
    lcd.setCursor(0, 1);
    lcd.print("     COIN      ");


    if (total > 0)
    {
      lcd.setCursor(0, 0);
      lcd.print("S1:" + String(set1) + " S2:" + String(set2) + " ");
      lcd.setCursor(0, 1);
      lcd.print("   COIN : " + String(total) + "    ");
    }
    {
      lcd.setCursor(0, 0);
      lcd.print(" PLEASE INSERT ");
      lcd.setCursor(0, 1);
      lcd.print("     COIN      ");
    }
  }
  if (stock1 == 0 ) {
    Blynk.logEvent("noty", "SNACK 1 IS OUT OF STOCK");

  }
  if (stock2 == 0 ) {
    Blynk.logEvent("noty", "SNACK 2 IS OUT OF STOCK");

  }
}
void billAcceptor() {
  count++;
  countreal = count - 100;
}

BLYNK_WRITE(V2)
{
  int reset1 = param.asInt(); // Get value as integer
  if (reset1)
  {
    stock1 = 10;
  }
}


BLYNK_WRITE(V3)
{
  int reset2 = param.asInt(); // Get value as integer
  if (reset2)
  {
    stock2 = 10;
  }
}

