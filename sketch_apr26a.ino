#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myservo;

#define ir1 9
#define ir2 8
#define ldr 4
#define flame 7
#define gas 6
#define led 2
#define buzzer 11

int count = 4;
void setup() {
  Serial.begin(9600);

  lcd.init(); 
  lcd.backlight();
  
  myservo.attach(5);// Servo setup
  myservo.write(0);

  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ldr, INPUT);
  pinMode(flame, INPUT);
  pinMode(gas, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);

 // Welcome Message 
  lcd.setCursor(0, 0);
  lcd.print(" WELCOME TO THE");
  lcd.setCursor(0, 1);
  lcd.print(" SMART PARKING!");
  delay(4000);
  lcd.clear();
}

void loop() {
  //Safety System
  int a = digitalRead(ldr);
  int b = digitalRead(flame);
  int c= digitalRead(gas);
Serial.print("ldr: ");
  Serial.println(a);
  delay(500);
  Serial.print("flame: ");
  Serial.println(b);
  delay(500);
  Serial.print("gas: ");
  Serial.println(c);
  delay(500);
  if (a == 1)
     digitalWrite(led, HIGH);
  else
    digitalWrite(led, LOW);

  if (b== 0) {
    digitalWrite(buzzer, HIGH);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("!!! ALERT !!!");
    lcd.setCursor(0, 1);
    lcd.print("Fire Detected");
    delay(3000);
    lcd.clear();
  } else if (c== 0) {
    digitalWrite(buzzer, HIGH);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("!!! ALERT !!!");
    lcd.setCursor(0, 1);
    lcd.print("Gas Leakage");
    delay(3000);
    lcd.clear();
  } else {
    digitalWrite(buzzer, LOW);
  }

  // ---- Parking System ----
  int x = digitalRead(ir1);
  int y = digitalRead(ir2);

  Serial.print("IR1: ");
  Serial.println(x);
  Serial.print("IR2: ");
  Serial.println(y);
  delay(500);

  if (x == 0 && count > 0) {
    count--;
    myservo.write(90);
    delay(500);
  } else {
    myservo.write(0);
  }

  if (y == 0 && count < 4) {
    count++;
  }

  // Display parking status
  lcd.setCursor(0, 0);
  lcd.print("PARKING STATUS>");

  lcd.setCursor(0, 1);
  if (count == 0) {
    lcd.print("      FULL      ");
  } else {
    lcd.print("SLOTS LEFT: ");
    lcd.print(count);
    lcd.print("   ");
  }

}
