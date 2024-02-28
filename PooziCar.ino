#include "PooziCar.h"
#include "clicli.h"

pooziCar pc(2, 4, 3, 7, 6, 5);
clicli c(pc);

void setup(){
  pc.begin(115200);
  c.begin();
}

void loop(){
  c.run();
}