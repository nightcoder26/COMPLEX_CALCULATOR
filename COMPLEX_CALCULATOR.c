/*
	A Calculator to perform various operations on 
	complex numbers using structures
*/
#include<stdio.h>
#include<math.h>

//Structure to store the real and complex part of a complex number
struct complex{
	float real;
	float comp;
};

struct complex add_c(struct complex a, struct complex b);
struct complex sub_c(struct complex a, struct complex b);
struct complex mul_c(struct complex a, struct complex b);
struct complex div_c(struct complex a, struct complex b);
struct complex conjugate(struct complex a);
float magnitude(struct complex a);

int main()
{
	float r1,c1,r2,c2;
	int choice;
	struct complex a,b;
	printf("------Complex number operations calculator----------\n");
	printf("\n1.Addition");
	printf("\n2.Subtraction");
	printf("\n3.Multiplication");
	printf("\n4.Division");
	printf("\n5.Conjugate");
	printf("\n6. Magnitude");
	printf("\nChoose an operation to perform");
	scanf("%d",&choice);
	if(choice > 0 && choice < 5 )
	{
		printf("\nEnter the real and imaginary part of the first complex number :");
		scanf("%f %f",&r1, &c1);
		printf("\nEnter the real and imaginary part of the second complex number :");
		scanf("%f %f",&r2, &c2);
		
		a.real = r1;
		a.comp = c1;
		b.real = r2;
		b.comp = c2;
	}
	else if(choice > 4 && choice < 7)
	{
		printf("\nEnter the real and imaginary part of the complex number :");
		scanf("%f %f",&r1, &c1);
		a.real = r1;
		a.comp = c1;
	}
	else
	{
		printf("\nEnter a valid choice ");
		return;
	}
	
	struct complex result;
	float result_mag;
	switch(choice)
	{
		case 1: result = add_c(a,b);
				break;
		case 2: result = sub_c(a,b);
				break;
		case 3: result = mul_c(a,b);
				break;
		case 4: result = div_c(a,b);
				break;
		case 5: result = conjugate(a);
				break;
		case 6: result_mag = magnitude(a);
				break;
	}
	
	if(choice == 6)
	{
		printf("\nThe result is %0.2f",result_mag);
	}
	
	else
	{
		printf("\nThe result is %0.2f + (%0.2f) i", result.real,result.comp);
	}
	

}


struct complex add_c(struct complex a, struct complex b)
{
	struct complex sum;
	sum.real = a.real + b.real;
	sum.comp = a.comp + b.comp;
	
	return sum;
}

struct complex sub_c(struct complex a, struct complex b)
{
	struct complex diff;
	diff.real = a.real +  b.real;
	diff.comp = a.comp + b.comp;
	return diff;
}

struct complex mul_c(struct complex a, struct complex b)
{
	struct complex result;
	result.real = (a.real * b.real) - (a.comp * b.comp);
	result.comp = (a.real * b.comp) + (a.comp * b.real);
	return result;
}

struct complex div_c(struct complex a, struct complex b)
{
	struct complex result;
	result.real = ((a.real * b.real) + (a.comp * b.comp)) / (pow(b.real,2) + pow(b.comp,2) );
	result.comp = ((a.comp * b.real) - (a.real * b.comp) ) / (pow(b.real,2) + pow(b.comp,2) );
	return result;
}

struct complex conjugate(struct complex a)
{
	struct complex result;
	result.real = a.real;
	result.comp = -(a.comp);
	return result;
}

float magnitude(struct complex a)
{
	float result;
	result = sqrt((a.real * a.real)+ (a.comp * a.comp));
	return result;
}
