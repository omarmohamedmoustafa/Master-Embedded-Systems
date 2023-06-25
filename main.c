/*
 * main.c
 *
 *  Created on: Jun 24, 2023
 *      Author: Omar_
 */

/*
  //EX 1 Write C Program to Print a Sentence
#include<stdio.h>
int main()
{
	printf("C Programming");
}
*/

//EX2: Write C Program to Print a Integer Entered by a User
//#include<stdio.h>
//int main()
//
//{
//	int x;
//	printf("Enter the number to display:\n");
//	fflush(stdout);
//	scanf("%d",&x);
//	printf("Number is : %d",x);
//	return 0;
//}


//EX4:Write C Program to Multiply two Floating Point Numbers

//#include<stdio.h>
//
//int main()
//{
//	float s;
//	float d;
//	printf("Enter the two numbers:");
//	fflush(stdout);
//	scanf("%f\n",&s);
//	scanf("%f",&d);
//
//	printf("Product = %f",s*d);
//}

//EX5: Write C Program to Find ASCII Value of a Character
//#include<stdio.h>
//
//int main ()
//{
//	char x;
//	printf("Enter a character:");
//	fflush(stdout);
//	scanf("%c",&x);
//	printf("Character is :%d",x);
//}

//Write Source Code to Swap Two Numbers
//#include<stdio.h>
//
//int main ()
//{
//float a,b;
//printf("Enter value of A :");
//fflush(stdout);
//scanf("%f",&a);
//printf("Enter value of B :");
//fflush(stdout);
//scanf("%f",&b);
//float temp;
//temp =a;
//a=b;
//b=temp;
//printf("After swapping   : A= %f\n",a);
//fflush(stdout);
//printf("After swapping   : B= %f",b);
//fflush(stdout);
//}

//without temp variable
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
}
