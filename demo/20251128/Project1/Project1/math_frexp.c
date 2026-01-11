#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main ()
{
   double x = 1024, fraction;
   int e;

   fraction = frexp(x, &e);
   printf("x = %.2lf = %.2lf * 2^%d\n", x, fraction, e);

   printf("%e\t%g\n", x, x);
   return(0);
}