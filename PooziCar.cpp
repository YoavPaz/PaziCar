#include "PooziCar.h"
#include <Wire.h>
#include <MPU6050_light.h>
#include <Arduino.h>


MPU6050 mpu(Wire);

pooziCar::pooziCar(int In1, int In2, int Ena1, int In3, int In4, int Ena2){
  in1 = In1;
  in2 = In2;
  in3 = In3;
  in4 = In4;
  ena1 = Ena1;
  ena2 = Ena2;
}

void pooziCar::begin(int bdrate){
  Serial.begin(bdrate);
  byte status = mpu.begin();
  Serial.print(F("MPU6050 status: "));
  Serial.println(status);
  while(status!=0){ }
  
  Serial.println(F("Calculating offsets, do not move MPU6050"));
  delay(1000);
 
  mpu.calcOffsets();
  Serial.println("Done!\n");
}

void pooziCar::move(int dir, int speed){
  switch (dir){
    case 0:
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    break;
    case 1:
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    break;
    case 2:
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    break;
    case 3:
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    break;
    default:

    break;
  }
  analogWrite(ena1, speed);
  analogWrite(ena2, speed);
}

void pooziCar::turnToAng(int ang, int KP){
  mpu.update();
  kp = KP;
  sp = ang;
  pv = mpu.getAngleZ();
  error = (sp - pv) * kp;
  Serial.println(error);
  analogWrite(ena1, error);
  analogWrite(ena2, error);
  if (error > 0){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }else{
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }
}