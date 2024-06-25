#include "SR04.h"
#include <Stepper.h>
#define TRIG_PIN 12
#define ECHO_PIN 11
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
//const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
//const int rolePerMinute = 15;         // Adjustable range of 28BYJ-48 stepper is 0~17 rpm

// initialize the stepper library on pins 8 through 11:
Stepper leftArm(2048, 8, 10, 9, 7);
//Stepper rightArm(2048, 3, 4, 5, 6);
long a;
void setup() {
  leftArm.setSpeed(15);
  //rightArm.setSpeed(15);
  // initialize the serial port:
  Serial.begin(9600);

}

void loop() { 
  a=sr04.Distance();
  Serial.println(a);
  if(a<25){
    Serial.println("clockwise");
    leftArm.step(2048);
    //rightArm.step(2048);
  }
    // step one revolution  in one direction:
  
  
}
