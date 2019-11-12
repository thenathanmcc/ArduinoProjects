/* Simple water level sensor test
 * Written by Nathan McCulloch
 */
#define SENSOR_PIN A5 // Analog pin the water sensor is connected to
#define READING_DELAY 5000 // Delay between each sensor reading
int sensor_val = 0; // Initial sensor value

void setup() {
  Serial.begin(9600); // Start serial console
}

void loop() {
  sensor_val = analogRead(SENSOR_PIN); // Read value on analog pin
  if (sensor_val <= 5){
    Serial.println("Water Level: Empty");
  } else if (sensor_val > 5 && sensor_val <= 450) {
    Serial.println("Water Level: Low");
  } else if (sensor_val > 450 && sensor_val <= 620) {
    Serial.println("Water Level: Medium");
  } else if (sensor_val > 620){
    Serial.println("Water Level: High");
  }
  delay(READING_DELAY);
}
