//Write source code to swap two numbers without temp variable
#include<stdio.h>
int main()
{
    float a,b;
    printf("Enter value of A :");
    fflush(stdout);
    scanf("%f",&a);
    printf("Enter value of B :");
    fflush(stdout);
    scanf("%f",&b);
    a = a + b;
    b = a - b;
    a = a - b;
    printf("After swapping   : A= %f\n",a);
    fflush(stdout);
    printf("After swapping   : B= %f",b);
    fflush(stdout);
    return 0;
}
