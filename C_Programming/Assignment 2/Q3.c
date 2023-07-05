//Write C program to find largest number among three numbers

int main()
{
	float x,y,z;
	scanf("%f%f%f",&x,&y,&z);
	if(x>y)
	{
		if(x>z)
			printf("X =%.2f",x);
		else
			printf("Z =%.2f",z);
	}
	else
	{
		if(y>z)
			printf("Y =%.2f",y);
		else
			printf("Z = %.2f",z);
	}
  return 0;
}
