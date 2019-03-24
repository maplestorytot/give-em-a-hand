#include <Servo.h>

Servo servo1;  // create servo object to control a servo
// twelve servo objects can be created on most boards
Servo servo2; // Define our Servo
Servo servo3;
//int trig = 10;
//int echo = 11;
//unsigned long duration;
//unsigned long distance;
int serialData;
bool recievedCommand;
int angle;
void setup()
{
   servo1.attach(8); 
   servo2.attach(9);
 
//  pinMode(trig, OUTPUT); // Sets the trigPin as an Output
//  pinMode(echo, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
//    Serial.println("--- Start Serial Monitor SEND_RCVE ---");
  recievedCommand=false;
}

void loop()
{
//  digitalWrite(trig, 0);
//  delay(5);
//
//  digitalWrite(trig, 1);
//  delay(10);
//  digitalWrite(trig, 0);  
//  duration = pulseIn(echo, HIGH);
//
//   distance = duration * 0.034 / 2;
//  Serial.print(distance);

  
  while(Serial.available()>0){
  
  serialData=Serial.read();
  delay(1);
  serialData=int(serialData);
//  char str[2];
//  str[0]=serialData;
//  str[1]='\0';
//  Serial.print("hey");
//  Serial.println(str);
  angle=serialData;
  Serial.write(serialData);
  if(serialData!=-1){
    recievedCommand=true;
  }else{
    recievedCommand=false;
  }
//  if(angle>75){
//      recievedCommand=true;
//    }else{
//      recievedCommand=false;
//    }
  }
  servo1.write(0);
  delay(1000);
  servo2.write(0);
  delay(1000);
  if(recievedCommand==true){
    
    servo1.write(angle);
    delay(1000);
    servo2.write(90);
//    servo2.write(
  /*  //if (serialData ==49) {
    // Make servo go to 0 degrees 
   servo1.write(0); 
   delay(1000); 
   // Make servo go to 90 degrees 
   servo1.write(90); 
   delay(1000); 
   // Make servo go to 180 degrees 
   servo1.write(180); 
   delay(1000);  
    }else{
    delay(1000);*/
 // } 
  }
  
  
  
   /*// Make servo go to 0 degrees 
   servo2.write(0); 
   delay(1000); 
   // Make servo go to 90 degrees 
   servo2.write(90); 
   delay(1000); 
   // Make servo go to 180 degrees 
   servo2.write(180); 
   delay(1000);*/
 
  delay(3000);


}
