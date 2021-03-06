// When this C++ VEXCode pro program is ran on a V5 Brain it would display any turned wheels
// to the VEX V5 Brain screen. For example, turning a wheel connected to a motor on port 1 would display 
// the port number and whether the motor is reversed.

#include "vex.h"
using namespace vex;

motor motors[] = {
            motor(PORT1, ratio18_1, false),
            motor(PORT2, ratio18_1, false),
            motor(PORT3, ratio18_1, false),
            motor(PORT4, ratio18_1, false),
            motor(PORT5, ratio18_1, false),
            motor(PORT6, ratio18_1, false),
            motor(PORT7, ratio18_1, false),
            motor(PORT8, ratio18_1, false),
            motor(PORT9, ratio18_1, false),
            motor(PORT10, ratio18_1, false),
            motor(PORT11, ratio18_1, false),
            motor(PORT12, ratio18_1, false),
            motor(PORT13, ratio18_1, false),
            motor(PORT14, ratio18_1, false),
            motor(PORT15, ratio18_1, false),
            motor(PORT16, ratio18_1, false),
            motor(PORT17, ratio18_1, false),
            motor(PORT18, ratio18_1, false),
            motor(PORT19, ratio18_1, false),
            motor(PORT20, ratio18_1, false)
};

int main() {

  int lineNumber = 1;
  for (int i=0; i < 20;i++) {motors[i].resetPosition();}
  Brain.Screen.print("Recording...");
  while (true)
  {
    task::sleep(100);
    for (int i=0; i < 20 ;i++)
    {
      if (fabs(motors[i].position(deg)) < 180){continue;}
      lineNumber++;
      Brain.Screen.setCursor(lineNumber, 1);
      Brain.Screen.print("Motor: %d Reversed: %s", i+1, motors[i].position(deg) > 0 ? "False" : "True");
      motors[i].setPosition(0, deg);
    }
    task::sleep(200);
  }
}

