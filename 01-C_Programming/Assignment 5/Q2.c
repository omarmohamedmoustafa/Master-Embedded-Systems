/* C Program to Add Two Complex Numbers by Passing Structure to a function*/
#include<stdio.h>
struct s_complex{
	float real;
	float imaginary;
};
struct s_complex sumComplex(struct s_complex s1,struct s_complex s2);

int main()
{
	struct s_complex s1;
	struct s_complex s2;
	struct s_complex sum;
	printf("Enter first number real part :\n");
	fflush(stdout);fflush(stdin);
	scanf("%f",&s1.real);
	printf("Enter first number imaginary part :\n");
	fflush(stdout);fflush(stdin);
	scanf("%f",&s1.imaginary);
	printf("Enter second number real part :\n");
	fflush(stdout);fflush(stdin);
	scanf("%f",&s2.real);
	printf("Enter second number imaginary part :\n");
	fflush(stdout);fflush(stdin);
	scanf("%f",&s2.imaginary);
	sum=sumComplex(s1,s2);
	printf("sum =%.2f + %.2fi",sum.real,sum.imaginary);
	return 0;
}
struct s_complex sumComplex(struct s_complex s1,struct s_complex s2)
{
	struct s_complex res;
	res.real=s1.real+s2.real;
	res.imaginary=s1.imaginary+s2.imaginary;
	return res;
}
