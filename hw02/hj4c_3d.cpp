/*
Name: HeeSeok Joo
UserId: hj4c
Homework #: 2
Problem #: 2b
Program Name: hj4c_3d.cpp
Pledge Signature:
*/

#include <stdio.h>
#include <math.h>
const float PI = 3.14159;

float distance(float x1,float y1,float z1,float x2,float y2,float z2);
float phi(float x,float y,float z);
float theta(float x,float y,float z);
float magnitude(float x,float y, float z);
float scalar(float x1,float y1,float z1,float x2,float y2,float z2);
float angle(float x1,float y1,float z1,float x2,float y2,float z2);

int main() {
  float x1,
    y1,
    z1,
    x2,
    y2,
    z2,
    xsum,
    ysum,
    zsum,
    xcross,
    ycross,
    zcross;
  
  printf("Enter the components of the first vector x1,y1,z1: \n");
  scanf("%f,%f,%f",&x1,&y1,&z1);
  printf("Enter the components of the second vector x2,y2,z2: \n");
  scanf("%f,%f,%f",&x2,&y2,&z2);

  xsum = x1+x2;
  ysum = y1+y2;
  zsum = z1+z2;
  xcross = (y1*z2)-(z1*y2);
  ycross = (z1*x2)-(x1*z2);
  zcross = (x1*y2)-(y1*x2); 

  printf("The phi angle of the sum of two vectors is %.1f degrees\n",
phi(xsum,ysum,zsum));
  printf("The theta angle of the sum of two vectors is %.1f degrees\n",
theta(xsum,ysum,zsum));
  printf("The magnitude of the sum of two vectors is %.1f \n",
magnitude(xsum,ysum,zsum));
  printf("The distance between two points is %.1f \n",
distance(x1,y1,z1,x2,y2,z2));
  printf("The scalar product (or dot product) of the two vectors is %.1f \n",
scalar(x1,y1,z1,x2,y2,z2));
  printf("The angle between the two vectors is %.1f degrees\n",
angle(x1,y1,z1,x2,y2,z2));
  printf("The cross product of the two vectors is <%.1f %.1f %.1f> \n",
xcross,ycross,zcross);
  printf("The magnitude of the cross product is %.1f \n",
(sqrt((pow(xcross,2))+(pow(ycross,2))+(pow(zcross,2)))));


  return 0;
}

float distance(float x1,float y1,float z1,float x2,float y2,float z2){
  return (sqrt((pow(x2-x1,2))+(pow(y2-y1,2))+(pow(z2-z1,2))));
}

float phi(float x,float y,float z){
  return ((180/PI)*atan(y/x));
}

float theta(float x,float y,float z){
  return ((180/PI)*atan((z)/(sqrt((pow(x,2))+(pow(y,2))))));
}

float magnitude(float x,float y, float z){
  return (distance(x,y,z,0,0,0));
}

float scalar(float x1,float y1,float z1,float x2,float y2,float z2){
  return ((x1*x2)+(y1*y2)+(z1*z2));
}

float angle(float x1,float y1,float z1,float x2,float y2,float z2){
  return ((180/PI)*acos((scalar(x1,y1,z1,x2,y2,z2))/(magnitude(x1,y1,z1)*magnitude(x2,y2,z2))));
}
