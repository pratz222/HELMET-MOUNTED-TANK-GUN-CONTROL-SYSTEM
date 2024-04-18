#include <RH_ASK.h>
#include <SPI.h>
#include "Wire.h"       
#include "I2Cdev.h"  

const int MPU_addr=0x68;         //I2C MPU6050 Address

RH_ASK rf_driver;
int16_t ax, ay;    

int minVal=-30000;  //245

int maxVal=30000;  //450

struct MyData {
  int X;
  int Y;
};

MyData data;


void setup()
{
  rf_driver.init();
  Wire.begin();                        //Begins I2C communication

  Wire.beginTransmission(MPU_addr);    //Begins Transmission with MPU6050

  Wire.write(0x6B);                    //Puts MPU6050 in Sleep Mode

  Wire.write(0);                       //Puts MPU6050 in power mode 

  Wire.endTransmission(true);          //Ends Trasmission
  Serial.begin(115200);


}


void loop()

{

  Wire.beginTransmission(MPU_addr); //Begins I2C transmission 

  Wire.write(0x3B);                 //Start with register 0x3B (ACCEL_XOUT_H)             

  Wire.endTransmission(false);

  Wire.requestFrom(MPU_addr,14,true); //Request 14 Registers from MPU6050


  ax=Wire.read()<<8|Wire.read(); //Obtain 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L) 

  ay=Wire.read()<<8|Wire.read(); //0x3B (ACCEL_YOUT_H) & 0x3C (ACCEL_YOUT_L)

    int xAng = map(ax,minVal,maxVal,-90,90); 

    int yAng = map(ay,minVal,maxVal,0,180);
       

    //data.X = map(xAng,minVal,maxVal,0,180); // As X value is from 0 to 360 deg
    //data.Y = map(yAng,minVal,maxVal,-90,90);     //ax, -90, 45, 30, 200
  data.X = xAng;
  data.Y = yAng;
  
  Serial.print("data.X");
  Serial.println(data.X);
    Serial.print("data.Y");
  Serial.println(data.Y);
       
    rf_driver.send((uint8_t *)&data, sizeof(data));
    rf_driver.waitPacketSent();
    delay(100);

}
