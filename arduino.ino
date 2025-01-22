//Install NewPing 
#include <NewPing.h>
#include <Servo.h>
Servo servo;

const int trigPin = 11;  
const int echoPin = 10; 
const int servoPin = 3;

// Left
const int M1_a = 4; //in1
const int M1_b = 5; //in2

// Right
const int M2_a = 6; //in3
const int M2_b = 7; //in4
 
NewPing sonar(trigPin,echoPin, 200);

void SetLeft(bool a,bool b){
  digitalWrite(M1_a,a);
  digitalWrite(M1_b,b);
}

void SetRight(bool a,bool b){
  digitalWrite(M2_a,a);
  digitalWrite(M2_b,b);
}

#define Forward() SetLeft(1,0);SetRight(1,0)
#define Backward() SetLeft(0,1);SetRight(0,1)
#define TurnLeft() SetLeft(0,1);SetRight(1,0)
#define TurnRight() SetLeft(1,0);SetRight(0,1)

void setup() {
  pinMode(trigPin, OUTPUT);  
	pinMode(echoPin, INPUT);  
	Serial.begin(9600); 
  servo.attach(servoPin);
  servo.write(90);
  delay(100);
  pinMode(M1_a, OUTPUT); pinMode(M1_b, OUTPUT); pinMode(M2_a, OUTPUT); pinMode(M2_b, OUTPUT);
}

void loop() {
  Serial.println(sonar.ping_cm());
  delay(100);
}
