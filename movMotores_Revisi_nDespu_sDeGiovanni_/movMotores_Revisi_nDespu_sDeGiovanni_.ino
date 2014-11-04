// This is our motor. Servo myMotor1; Servo myMotor2; Servo myMotor3; Servo myMotor4;
#include <Servo.h>
String incomingString;
  Servo myMotor1;// = 0;
  Servo myMotor2;// = 0;
  Servo myMotor3;// = 0;
  Servo myMotor4;
  
void setup() 
{
  myMotor1.attach(9);
  myMotor2.attach(8);
  myMotor3.attach(7);
  myMotor4.attach(6);
  
  Serial.begin(9600);
}

void loop() 
{
  int val = 0;
  if(Serial.available() > 0)
  {
    char ch = Serial.read();
    if (ch != 10){
      incomingString += ch;
  }
  else
  {
    if (val > -1 && val < 181)
    {
      while(val < 180)
      {
        val = val + 5;
        myMotor1.write(val);
        myMotor2.write(val);
        myMotor3.write(val);
        myMotor4.write(val);
      }
    }
    else
    {
      Serial.println("Value is NOT between 0 and 180");
      Serial.println("Error with the input");
    }
    
    incomingString = "";
  }
  } 
else { 
   while (val > 0) {
     val = val - 5;
     myMotor1.write(val);
     myMotor2.write(val);
     myMotor3.write(val);
     myMotor4.write(val); 
    }
  }

}
