//Write Source Code to Swap Two Numbers
#include<stdio.h>
int main ()
{
  float a,b;
  printf("Enter value of A :");
  fflush(stdout);
  scanf("%f",&a);
  printf("Enter value of B :");
  fflush(stdout);
  scanf("%f",&b);
  float temp;
  temp =a;
  a=b;
  b=temp;
  printf("After swapping   : A= %f\n",a);
  fflush(stdout);
  printf("After swapping   : B= %f",b);
  fflush(stdout);
  return 0;
}
