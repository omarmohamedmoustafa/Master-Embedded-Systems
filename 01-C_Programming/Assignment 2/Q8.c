//calculator using switch case
#include<stdio.h>
int main()
{
	char process;
	float operand1,operand2;
	printf("Enter Operation :\n");
	fflush(stdout);
	scanf("%c",&process);
	printf("Enter Operands :\n");
	fflush(stdout);
	scanf("%f%f",&operand1,&operand2);
	float res=0.0;
	switch(process)
	{
		case '+':
			res=operand1+operand2;
		break;
		case '-':
			res=operand1-operand2;
		break;
		case '*':
			res=operand1*operand2;
		break;
		case '/':
			res=operand1/operand2;
		break;
		default:
			printf("Enter a valid process");
	}
	printf("Result = %.1f",res);
	return 0;
}
