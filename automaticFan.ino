




#include <LiquidCrystal.h>
int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;
int thermPin = A5;
float currentTemp;
int dt = 2000;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  pinMode(thermPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(4, 0);
  lcd.print("temp:");
  
  while(true){
    currentTemp = (float(analogRead(thermPin))*5./1023.) * -9. + 104.;
    lcd.setCursor(3,1);
    lcd.print(currentTemp);
    lcd.setCursor(10,1);
    lcd.print("\xDF""F");
    delay(dt);
  }
}
