/* Simple program to turn a LED on and off
 * Written by Nathan McCulloch
 */
 #define LED_PIN 13
 #define DELAY_PERIOD 5000 

void setup() {
  //Set pin mode
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(DELAY_PERIOD);
  digitalWrite(LED_PIN, LOW);
  delay(DELAY_PERIOD);
}
