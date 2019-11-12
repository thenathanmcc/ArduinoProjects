/* Simple program to test a I2C Liquid Crystal Display
 * Written by Nathan McCulloch
 */


#include <LiquidCrystal_I2C.h>
#include <Wire.h>


LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {
  lcd.begin(16, 2);
  lcd.backlight(); //Enable LCD backlight
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Test 1");
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("Test 2");
  delay(5000);
  lcd.clear();
}
