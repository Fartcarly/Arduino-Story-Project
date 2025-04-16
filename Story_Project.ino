#include <Servo.h> //servo library

//PIN INITIALIZATION (1-13)

const int ledPin1 = 13; //luigis idea lightbulb scene 2
const int newsLed1 = 12; //news lights scene 3
const int newsLed2 = 11; 
const int switchPin1Light = 10; //set up light switch pin with alligator clips
  int switchState1;  //tracks the state of the switch
const int switchPin2Bullet = 9; //bullet switch scene 
  int switchState2;
const int switchPin3Twitter = 8; //slider twitter switch for news scene 4
  int switchState3; 
const int switchPin3World =  7;//luigi stand switch scene 5
  int switchState4;

int SceneNumber = 2; //tells the program which scene is currently being ran

Servo armServo; //creates servo variable for moving luigi's arm
Servo runServo; //luigi running to mcdonalds motor
Servo worldServo; // moves the people of the world holding hands


void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600); // Start serial communication

//-------SCENE 2 light---------//
armServo.attach(6); //attaches arm servo to pin 8
pinMode(switchPin1Light, INPUT);
pinMode(ledPin1, OUTPUT); 

//-------SCENE 3 bullet---------//
runServo.attach(5);
pinMode(switchPin2Bullet, INPUT);

//-------SCENE 4 twitter---------//
pinMode(switchPin3Twitter, INPUT);
pinMode(newsLed1, OUTPUT); //sets the LEDs as outputs
pinMode(newsLed2, OUTPUT);

//-------SCENE 5 world---------//
worldServo.attach(4);
pinMode(switchPin3World, INPUT);
}

void moveMotorArm() {  //moves arm Servo
  int pos = 0;    // variable to store the servo position
  for (pos = 30; pos <= 150; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    armServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 150; pos >= 30; pos -= 1) { // goes from 180 degrees to 0 degrees
    armServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
}
void moveMotorRun() {  //moves run Servo
  int pos = 0;    // variable to store the servo position
  for (pos = 70; pos <= 110; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    runServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 110; pos >= 70; pos -= 1) { // goes from 180 degrees to 0 degrees
    runServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
}

void moveMotorWorld() {  //moves world Servo
  int pos = 0;    // variable to store the servo position
  for (pos = 70; pos <= 110; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    worldServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 110; pos >= 70; pos -= 1) { // goes from 180 degrees to 0 degrees
    worldServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
}

void Light(){
//-------SCENE 2 (LIGHTBULB SCENE)-----------//
  switchState1 = digitalRead(switchPin1Light);
if (digitalRead(switchPin1Light)==HIGH){
  Serial.println("LIGHT PRESSED"); // Print message when button is pressed
  digitalWrite(ledPin1, LOW); //turn light on
  moveMotorArm();

}else{
  if (digitalRead(switchPin1Light)==LOW){
    digitalWrite(ledPin1, HIGH); //turn light off
    // Serial.println("Button Released"); // Print message when button is not pressed
  }
  }
}

void Bullet(){
//--------SCENE 3 (BULLET)-----------//
switchState2 = digitalRead(switchPin2Bullet);

if (digitalRead(switchPin2Bullet)==HIGH){
  moveMotorRun();
  Serial.println("Bullet PRESSED"); // Print message when button is pressed

}else{
  if (digitalRead(switchPin2Bullet)==LOW){
    // Serial.println("Button Released"); // Print message when button is not pressed
  }
  }
}

void Twitter(){
//-------SCENE 4 (TWITTER)--------//

//I'm thinking for this scene, there could be a track on the floor that has a swich at the END that triggers this interaction. the twitter symbol could be on a stick that the player moves
  switchState3 = digitalRead(switchPin3Twitter);
if (switchState3 == HIGH) {
  digitalWrite(newsLed1, LOW); //turns lights on
  digitalWrite(newsLed2, LOW);
  Serial.println("TWITTER PRESSED"); // Print message when button is pressed

}else{
  if (digitalRead(switchPin3Twitter)==LOW){
  digitalWrite(newsLed1, HIGH); //turns lights OFF
  digitalWrite(newsLed2, HIGH);
    // Serial.println("Button Released"); // Print message when button is not pressed
  }
  delay(100);
  }
}

void World(){
  switchState4 = digitalRead(switchPin3World);
if (digitalRead(switchPin3World)==HIGH){
  moveMotorWorld();
  Serial.println("WORLD PRESSED"); // Print message when button is pressed

}else{
  if (digitalRead(switchPin3World)==LOW){
    // Serial.println("Button Released"); // Print message when button is not pressed
  }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
Light();
Bullet();
Twitter();
World();

}
