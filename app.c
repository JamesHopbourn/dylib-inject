#include <stdio.h>

#include "libmymath.h"

int main(int argc, char const *argv[]) {
  double r = 4.0;
  double n = 5.0;

  printf("Radius %.2f, area is %.2f \n", r, CircleArea(r));
  printf("Radius %.2f, circumference is %.2f \n", r, CircleCircum(r));
  printf("%.2f to the power of 2 is %.2f \n", n, PowerOf2(n));
  printf("%.2f to the power of 3 is %.2f \n", n, PowerOf3(n));

  return 0;
}
