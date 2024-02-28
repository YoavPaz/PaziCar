#ifndef CLICLI_H
#define CLICLI_H
#include "PooziCar.h"

 class clicli {

  public:
   clicli(pooziCar &mypoozicar) ;
   void begin();   //must be called from  void setup()
   void run();   //must be called from  void loop()

  private:
   pooziCar &mypoozicar;
   int number;

 };
#endif 