//Install NewPing 
#include <NewPing.h>


const int trigPin = 11;  
const int echoPin = 10; 
NewPing sonar(trigPin,echoPin, 200);


void setup() {
  pinMode(trigPin, OUTPUT);  
	pinMode(echoPin, INPUT);  
	Serial.begin(9600); 

}

void loop() {
  Serial.print(sonar.ping_cm());
  delay(10000);
}
