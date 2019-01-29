
#include <Servo.h>//Using servo library to control ESC

Servo esc; //Creating a servo class with name as esc

int escalon = 1200;
unsigned long tiempo;

void setup()
{

Serial.begin(9600);


  esc.attach(8); //Specify the esc signal pin,Here as D8

  esc.writeMicroseconds(1000); //initialize the signal to 1000
  delay(3000);
  esc.writeMicroseconds(1300);
  delay(500);
  esc.writeMicroseconds(1000);


}

void loop()
{

  
  tiempo = millis();

  esc.writeMicroseconds(escalon);

  if(tiempo >= 40000)
  {
    escalon = 1280;
  }

}
