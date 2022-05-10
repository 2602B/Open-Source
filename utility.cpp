#include "../include/utility.h"
#include <stdlib.h>
#include <math.h>
// #include "vex.h"

float PI = 3.14159265;

int leftAngle(int currentAngle, int targetAngle){
  int turnAngle = 360 - ((360 - currentAngle + targetAngle) % 360);
  if (turnAngle == 360){return 0;}
  return -turnAngle;
}

int rightAngle(int currentAngle, int targetAngle){
  int turnAngle = (360 - currentAngle + targetAngle) % 360;
  if (turnAngle == 360){return 0;}
  return turnAngle;
}

int getTurnError(int currentAngle, int targetAngle)
{
  if (abs(leftAngle(currentAngle, targetAngle)) < abs(rightAngle(currentAngle, targetAngle))){
    return leftAngle(currentAngle, targetAngle);
  }
  else{return rightAngle(currentAngle, targetAngle);}
}

float square(float x)
{
  return x * x;
}

float radianToDegree(float x)
{
  return x * (180.0 / PI);
}
float degreeToRadian(float x)
{
  return x * (PI / 180.0);
}
/////////////////////////////////////
// Unit Interface: Strategy Pattern
/////////////////////////////////////
double UnitInterface::unitToMM(double amount){return 0;};
double UnitInterface::MMToUnit(double amount){return 0;};

double INCHES_::unitToMM(double amount){return amount * 25.4f;};
double INCHES_::MMToUnit(double amount){return amount / 25.4f;};

double MM_::unitToMM(double amount){return amount;};
double MM_::MMToUnit(double amount){return amount;};

double CM_::unitToMM(double amount){return amount * 10.0f;};
double CM_::MMToUnit(double amount){return amount / 10.0f;};

double FEET_::unitToMM(double amount){return amount * 305.0f;};
double FEET_::MMToUnit(double amount){return amount / 305.0f;};

double METER_::unitToMM(double amount){return amount * 1000.0f;};
double METER_::MMToUnit(double amount){return amount / 1000.0f;};

double MILES_::unitToMM(double amount){return amount * 1.609f * 10 * 10 * 10 * 10 * 10 * 10;};
double MILES_::MMToUnit(double amount){return amount / 1.609f * 10 * 10 * 10 * 10 * 10 * 10;};

double SMOOT_::unitToMM(double amount){return amount * 1701.8f;};
double SMOOT_::MMToUnit(double amount){return amount / 1701.8f;};

double convert(double amount, UnitInterface *firstType, UnitInterface *newType)
{
  double amountMM = firstType->unitToMM(amount);
  return round(newType->MMToUnit(amountMM) * 10) / 10;
}

float getTargetAngle(float currentX, float targetX, float currentY, float targetY)
{
  float targetAngle = atan((currentX - targetX) / (currentY - targetY));
  targetAngle = radianToDegree(targetAngle);
  if (currentX - targetX > 0 && currentY - targetY > 0)
  {return targetAngle + 180;}
  else if (currentX - targetX > 0 && currentY - targetY < 0)
  {return targetAngle + 360;}
  else if (currentX - targetX < 0 && currentY - targetY < 0)
  {return targetAngle + 0;}
  return targetAngle -180;
}

float dist(int x1, int y1, int x2, int y2)
{
    // Calculating distance
    return sqrt(pow(x2 - x1, 2) +
                pow(y2 - y1, 2) * 1.0);
}