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
  // put your setup code here, to run once:
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
  //  lcd.begin();
  //  lcd.backlight();
  //  lcd.setCursor(0, 0);
  //  lcd.print(" PLEASE INSERT ");
  //  lcd.setCursor(0, 1);
  //  lcd.print("     COIN      ");
  Timer = millis();
  virtualLCD.print(0, 0, "Stock1 :" + String(stock1) + "   ");
  virtualLCD.print(0, 1, "Stock2 :" + String(stock2) + "   ");
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  if (countreal == 1) {
    countreal = 0;
    count = 100;
    total = total + 0.10;
    //    lcd.setCursor(0, 0);
    //    lcd.print("S1: RM" + String(set1) + " S2: RM" + String(set2) + " ");
    //    lcd.setCursor(0, 1);
    //    lcd.print("   COIN : " + String(total) + "    ");
    virtualLCD.print(0, 1, "   COIN : " + String(total) + "    ");

  }
  else if (countreal == 2) {
    countreal = 0;
    count = 100;
    total = total + 0.20;
    //    lcd.setCursor(0, 0);
    //    lcd.print("S1: RM" + String(set1) + " S2: RM" + String(set2) + " ");
    //    lcd.setCursor(0, 1);
    //    lcd.print("   COIN : " + String(total) + "    ");
    virtualLCD.print(0, 1, "   COIN : " + String(total) + "    ");

  }
  else if (countreal == 3) {
    countreal = 0;
    count = 100;
    total = total + 0.50;
    //    lcd.setCursor(0, 0);
    //    lcd.print("S1: RM" + String(set1) + " S2: RM" + String(set2) + " ");
    //    lcd.setCursor(0, 1);
    //    lcd.print("   COIN : " + String(total) + "    ");
    virtualLCD.print(0, 1, "   COIN : " + String(total) + "    ");

  }
  else if (countreal == 4) {
    countreal = 0;
    count = 100;
    total = total + 0.10;
    //    lcd.setCursor(0, 0);
    //    lcd.print("S1: RM" + String(set1) + " S2: RM" + String(set2) + " ");
    //    lcd.setCursor(0, 1);
    //    lcd.print("   COIN : " + String(total) + "    ");
    virtualLCD.print(0, 1, "   COIN : " + String(total) + "    ");

  }
  else if (countreal == 5) {
    countreal = 0;
    count = 100;
    total = total + 0.20;
    //    lcd.setCursor(0, 0);
    //    lcd.print("S1: RM" + String(set1) + " S2: RM" + String(set2) + " ");
    //    lcd.setCursor(0, 1);
    //    lcd.print("   COIN : " + String(total) + "    ");
    virtualLCD.print(0, 1, "   COIN : " + String(total) + "    ");

  }
  else  if (countreal == 6) {
    countreal = 0;
    count = 100;
    total = total + 0.50;
    //    lcd.setCursor(0, 0);
    //    lcd.print("S1: RM" + String(set1) + " S2: RM" + String(set2) + " ");
    //    lcd.setCursor(0, 1);
    //    lcd.print("   COIN : " + String(total) + "    ");
    virtualLCD.print(0, 1, "   COIN : " + String(total) + "    ");

  }
  else {

  }


  if (digitalRead(5) == LOW )
  {
    if (total >= set1 && stock1 >= 1)
    {

      total = 0;
      stock1--;
      virtualLCD.print(0, 0, "Stock1 : " + String(stock1) + "  ");
      virtualLCD.print(0, 1, "   SNACK 1  ");
      delay(1000);
      digitalWrite(MOTOR1, LOW);
      delay(timedelay);
      digitalWrite(MOTOR1, HIGH);
      virtualLCD.clear();

    }
    else {

      virtualLCD.print(0, 1, "   NO STOCK/MONEY  ");

      virtualLCD.clear();
    }
  }


    if (digitalRead(4) == LOW )
  {
    if (total >= set2 && stock2 >= 1)
    {

      total = 0;
      stock2--;
      virtualLCD.print(0, 0, "Stock2 : " + String(stock2) + "  ");
      virtualLCD.print(0, 1, "   SNACK 2  ");
      delay(1000);
      digitalWrite(MOTOR2, LOW);
      delay(timedelay);
      digitalWrite(MOTOR2, HIGH);
      virtualLCD.clear();

    }
    else {

      virtualLCD.print(0, 1, "   NO STOCK/MONEY  ");

      virtualLCD.clear();
    }
  }
}
