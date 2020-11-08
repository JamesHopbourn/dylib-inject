/* ====================================================
#   Copyright (C) 2020 All rights reserved.
#
#   Author        : James Hopbourn
#   Email         : JamesHopbourn@gmail.com
#   File Name     : libmath.c
#   Last Modified : 2020-10-29 11:49
#   Describe      : 
#
# ====================================================*/

#include <stdio.h>
#define PI 3.1415;
 
double CircleArea (double radius);
double CircleCircum (double radius);

double PowerOf2 (double number);
double PowerOf3 (double number);
 
int main ( )
{
 
 double r = 4.0;
 double n = 5.0;

 printf ("Radius %.2f, area is %.2f \n", r, CircleArea(r));
 printf ("Radius %.2f, circumference is %.2f \n", r, CircleCircum(r));
 printf ("%.2f to the power of 2 is %.2f \n", n, PowerOf2(n));
 printf ("%.2f to the power of 3 is %.2f \n", n, PowerOf3(n));

 return 0;

 
}
 
