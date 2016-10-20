/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

const int pressurePlatePin = 2;
const int motorPin = 4;

int servoOpenPosition = 90;    // variable to store the servo position
int servoClosedPosition = 0;    // variable to store the servo position

int reelTime = 1000;
int hangTime = 5000;

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(pressurePlatePin, INPUT);
  digitalWrite(pressurePlatePin, HIGH);
  pinMode(motorPin, OUTPUT);

  myservo.write(servoClosedPosition);              // tell servo to go to position in variable 'pos'
  delay(500);  
}

void loop() {
  if(triggered()){
    dropSpider();
    delay(hangTime);
    raiseSpider();
  }
  
}

bool triggered(){
  int buttonState = digitalRead(pressurePlatePin);
  if(buttonState == LOW)
    return true;
  else
    return false;
}


void dropSpider() {
  myservo.write(servoOpenPosition);
}

void raiseSpider() {
  runMotor();
  myservo.write(servoClosedPosition);
}

void runMotor(){
  digitalWrite(motorPin, HIGH);
  delay(reelTime);
  digitalWrite (motorPin, LOW);
}

