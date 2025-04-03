#include <Servo.h>

//PIN INITIALIZATION (1-13)

const int ledPin1 = 13; //luigis idea lightbulb scene 2
const int newsLed1 = 12; //news lights scene 3
const int newsLed2 = 11; 
const int switchPin1Light = 10; //set up light switch pin with alligator clips
const int switchPin2Slider = 9; //slider twitter switch for news scene 3
const int switchPin3Bullet = 8; //bullet switch scene 4
const int switchPin4Stand =  7;//luigi stand switch scene 5

Servo armServo; //creates servo variable for moving luigi's arm
Servo runServo; //luigi running to mcdonalds motor
Servo worldServo; // moves the people of the world holding hands


void setup() {
  // put your setup code here, to run once:
armServo.attach(8); //attaches arm servo to pin 8
pinMode(switchPin1Light, INPUT);

runServo.attach(7);
pinMode(switchPin3Bullet, INPUT);

worldServo.attach(6);
pinMode(switchPin4Stand, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if (digitalRead(switchPin1)==HIGH){
  armservo.write(180); //servo angle
}else{
  armservo.write(0);
  }
}
