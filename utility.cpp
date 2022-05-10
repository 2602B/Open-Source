#include <stdlib.h>
#include <math.h>

float PI = 3.14159265;

// Considering the robots current angle, return how far left the robot would need to turn to reach the target angle.
int leftAngle(int currentAngle, int targetAngle){
  int turnAngle = 360 - ((360 - currentAngle + targetAngle) % 360);
  if (turnAngle == 360){return 0;}
  return -turnAngle;
}

// Considering the robots current angle, return how far right the robot would need to turn to reach the target angle.
int rightAngle(int currentAngle, int targetAngle){
  int turnAngle = (360 - currentAngle + targetAngle) % 360;
  if (turnAngle == 360){return 0;}
  return turnAngle;
}

// considering the left and right error, return how much the robot would need to turn for the lesser distance.
// a negative value represents a left hand turn, while right is positive.
int getTurnError(int currentAngle, int targetAngle)
{
  if (abs(leftAngle(currentAngle, targetAngle)) < abs(rightAngle(currentAngle, targetAngle))){
    return leftAngle(currentAngle, targetAngle);
  }
  else{return rightAngle(currentAngle, targetAngle);}
}
// return the square of a value.
float square(float x)
{
  return x * x;
}
// convert radians to degrees.
float radianToDegree(float x)
{
  return x * (180.0 / PI);
}

// convert degrees to radians.
float degreeToRadian(float x)
{
  return x * (PI / 180.0);
}

// considering the robots current X and Y position, calulate the heading the robot would need to drive at
// to a new X, Y position.
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

// calulate the distance from a point
float dist(int x1, int y1, int x2, int y2)
{
    // Calculating distance
    return sqrt(pow(x2 - x1, 2) +
                pow(y2 - y1, 2) * 1.0);
}
