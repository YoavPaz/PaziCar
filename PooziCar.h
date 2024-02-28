#ifndef POOZICAR
#define POOZICAR

class pooziCar{
  public:
  pooziCar(int In1, int In2, int Ena1, int In3, int In4, int Ena2);
  void begin(int bdrate);
  void move(int dir, int speed);
  void turnToAng(int ang, int KP);
  private:
  int in1;
  int in2;
  int ena1;
  int in3;
  int in4;
  int ena2;

  // PID
  int pv;
  int sp;
  int kp;
  int error;
};

#endif