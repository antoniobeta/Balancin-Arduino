
#include <Servo.h>//Using servo library to control ESC

Servo esc; //Creating a servo class with name as esc

int Input = 0;

void setup()
{

  Serial.begin(9600);

  esc.attach(8); //Specify the esc signal pin,Here as D8

  esc.writeMicroseconds(1000); //initialize the signal to 1000
  delay(3000);
  esc.writeMicroseconds(1300);
  delay(500);
  esc.writeMicroseconds(1000);

  
  //El potenciometro esta conectado a A1. 
  Input = analogRead(A1);
}

void loop()
{
  byte Outesc;
  int OutescM;
  byte InputM;

  
  Input = analogRead(A1);
  
  //Con map ponemos Input dentro del rango de una variable byte.
  InputM=map(Input, 0, 1023, 0, 255);
  //Enviamos el dato a Simulink.
  Serial.write(InputM);

  //Leemos el puerto para obtener los datos que nos envia Simulink

   if(Serial.available()){
    Outesc = Serial.read();
  }
  

  //Simulink tambien nos envia un byte, asi que tenemos que volver a hacer un map
  //para adaptarlo al rango que entiende nuestro motor. 
  OutescM = map(Outesc, 0, 255, 1200, 1400);

  esc.writeMicroseconds(OutescM);
  
  //este delay es para estabilizar el conversor.
  delay(20);
}
