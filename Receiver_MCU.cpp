#include <RH_ASK.h>
#include <SPI.h>
#include "Wire.h"       
#include "I2Cdev.h"  
#include "ServoTimer2.h"

RH_ASK rf_driver;

ServoTimer2 servo1;
ServoTimer2 servo2;

struct MyData {
 int X; 
 int Y;
};

MyData data;

void setup()
{
    Serial.begin(115200);
    rf_driver.init();
    servo1.attach(5);    // Placed ABOVE as turret
    servo2.attach(6);   // Placed DOWN as Base

}



void loop()
{

//int data;
  uint8_t datalen = sizeof(data);
  if (rf_driver.recv((uint8_t*)&data, &datalen))
  {
      int aX = (int)data.X ;
      int aY = (int)data.Y ;
        Serial.print("ax ");
  Serial.println(aX);

    Serial.print("ay");
  Serial.println(aY);

       servo1.write(aX);  // PIN 5
           
       servo2.write(aY); // PIN 6
  }
}
