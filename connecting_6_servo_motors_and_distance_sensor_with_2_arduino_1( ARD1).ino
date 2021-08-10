#include <Servo.h>;

int echo = 2; int trigger = 4;
int distance; long duration;

Servo ServoRightArm1;
Servo ServoRightArm2;
Servo ServoRightArm3;
Servo ServoLeftArm1;
Servo ServoLeftArm2;
Servo ServoLeftArm3;


void setup()
{
       ServoRightArm1.write(0);
       ServoRightArm2.write(0);
       ServoRightArm3.write(0);
       ServoLeftArm1.write(0);
       ServoLeftArm2.write(0);
       ServoLeftArm3.write(0);


 
  ServoRightArm1.attach(3);
  ServoRightArm2.attach(5);
  ServoRightArm3.attach(6);
  ServoLeftArm1.attach(9);
  ServoLeftArm2.attach(10);
  ServoLeftArm3.attach(11);
  
   
  Serial.begin(9600);
  pinMode(trigger, OUTPUT);             
  pinMode(echo, INPUT);               
  pinMode(A0, INPUT);
  
}

void initialPosition(){
  
       ServoRightArm1.write(0);
       ServoRightArm2.write(0);
       ServoRightArm3.write(0);
       ServoLeftArm1.write(0);
       ServoLeftArm2.write(0);
       ServoLeftArm3.write(0);
  delay(1500);
}



int gettingDistance(){
  
  digitalWrite(trigger,LOW);
  delayMicroseconds(2);
  
  
  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigger,LOW);
  
  duration = pulseIn(echo, HIGH);
  
  distance = (duration/2)* 0.0343;
  
  return distance ;

  
}

void loop()
{
  
  {
  while(gettingDistance() > 45){  continue; }             
  int startTime = millis();                            
  while( gettingDistance()<45){                            
 
   int newTime = millis();                            

  if (newTime - startTime > 3000){                    
    Serial.write('1');                                
    Serial.println('\n');
    
     Serial.println("Doing movement and open the screen...");
  
      ServoRightArm1.write(180);
      ServoRightArm2.write(0);
      ServoRightArm3.write(90);
      delay(850);
      ServoRightArm1.write(45);
      delay(850);
      ServoRightArm3.write(0);
      delay(1500);
      
      initialPosition();
      Serial.println("Done");
    break; }   
  }
  
   while(gettingDistance() ){ continue; }              

}
}
  

    
    
