/* Simple program to run a 28BYJ-48 Stepper motor.
 * Written by Nathan McCulloch
 * N.B. The 28BYJ-48 Stepper motor requires 2048 steps for a complete revolution and the max speed is 500 steps/sec.
 * This means that it takes just over 4 seconds to do a complete rotation
 */
#define STEPPER_PIN_1 9
#define STEPPER_PIN_2 10
#define STEPPER_PIN_3 11
#define STEPPER_PIN_4 12
#define INPUT_PIN 5 //Connected to a switch to toggle between clockwise and anticlockwise rotation
#define MINIMUM_STEP_DELAY 2 //Minimum delay required by the motor between steps is 2 milliseconds

int step_position = 0; //Used to keep track of the current step positon.
int clockwise = false; //Direction motor should rotate

void setup() {
  //Set the pin modes
  pinMode(STEPPER_PIN_1, OUTPUT);
  pinMode(STEPPER_PIN_2, OUTPUT);
  pinMode(STEPPER_PIN_3, OUTPUT);
  pinMode(STEPPER_PIN_4, OUTPUT);
}

void loop() {
  int reading = digitalRead(INPUT_PIN);
  switch(reading) {
    case 0:
      clockwise = false;
      break;
    case 1:
      clockwise = true;
      break;
    default:
      clockwise = false;
  }
  oneStep(clockwise);
  delay(MINIMUM_STEP_DELAY);
}

/* 
 * Function: oneStep
 * ------------------
 * Move the motor one step
 * 
 * clockwise: true if the direction of the motor is clockwise
 */
void oneStep(bool clockwise){
  if (clockwise) {
    step_clockwise(step_position);
  } else {
    step_anticlockwise(step_position);
  }
  step_position = (step_position + 1) % 4; // Update position of step
}


/* 
 * Function: step_clockwise
 * ------------------------
 * Move the motor one step in the clockwise direction
 * 
 * step_position: step position to move into
 */
void step_clockwise(int step_position) {
  switch(step_position){
      case 0:
        digitalWrite(STEPPER_PIN_1, HIGH);
        digitalWrite(STEPPER_PIN_2, LOW);
        digitalWrite(STEPPER_PIN_3, LOW);
        digitalWrite(STEPPER_PIN_4, LOW);
        break;
      case 1:
        digitalWrite(STEPPER_PIN_1, LOW);
        digitalWrite(STEPPER_PIN_2, HIGH);
        digitalWrite(STEPPER_PIN_3, LOW);
        digitalWrite(STEPPER_PIN_4, LOW);
        break;
      case 2:
        digitalWrite(STEPPER_PIN_1, LOW);
        digitalWrite(STEPPER_PIN_2, LOW);
        digitalWrite(STEPPER_PIN_3, HIGH);
        digitalWrite(STEPPER_PIN_4, LOW);
        break;
      case 3:
        digitalWrite(STEPPER_PIN_1, LOW);
        digitalWrite(STEPPER_PIN_2, LOW);
        digitalWrite(STEPPER_PIN_3, LOW);
        digitalWrite(STEPPER_PIN_4, HIGH);
        break;
    }
}

/* 
 * Function: step_anticlockwise
 * ------------------------
 * Move the motor one step in the anticlockwise direction
 * 
 * step_position: step position to move into
 */
void step_anticlockwise(int step_position) {
  switch(step_position){
      case 0:
        digitalWrite(STEPPER_PIN_1, LOW);
        digitalWrite(STEPPER_PIN_2, LOW);
        digitalWrite(STEPPER_PIN_3, LOW);
        digitalWrite(STEPPER_PIN_4, HIGH);
        break;
      case 1:
        digitalWrite(STEPPER_PIN_1, LOW);
        digitalWrite(STEPPER_PIN_2, LOW);
        digitalWrite(STEPPER_PIN_3, HIGH);
        digitalWrite(STEPPER_PIN_4, LOW);
        break;
      case 2:
        digitalWrite(STEPPER_PIN_1, LOW);
        digitalWrite(STEPPER_PIN_2, HIGH);
        digitalWrite(STEPPER_PIN_3, LOW);
        digitalWrite(STEPPER_PIN_4, LOW);
        break;
      case 3:
        digitalWrite(STEPPER_PIN_1, HIGH);
        digitalWrite(STEPPER_PIN_2, LOW);
        digitalWrite(STEPPER_PIN_3, LOW);
        digitalWrite(STEPPER_PIN_4, LOW);
        break;
    }
}
