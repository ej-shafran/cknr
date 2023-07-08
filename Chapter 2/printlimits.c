#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
	printf("char min: %d\n", CHAR_MIN);
	printf("char max: %d\n", CHAR_MAX);
	printf("unsigned char max: %u\n", UCHAR_MAX);
	printf("\n");

	printf("int min: %d\n", INT_MIN);
	printf("int max: %d\n", INT_MAX);
	printf("unsigned int max: %u\n", UINT_MAX);
	printf("\n");

	printf("float min: %f\n", FLT_MIN);
	printf("float max: %f\n", FLT_MAX);
	printf("\n");

	printf("double min: %f\n", DBL_MIN);
	printf("double max: %f\n", DBL_MAX);
	printf("\n");

	printf("long double min: %Lf\n", LDBL_MIN);
	printf("long double max: %Lf\n", LDBL_MAX);
	printf("\n");

	printf("long int min: %ld\n", LONG_MIN);
	printf("long int max: %ld\n", LONG_MAX);
	printf("unsigned long int max: %lu\n", ULONG_MAX);
	printf("\n");

	printf("long long int min: %Ld\n", LLONG_MIN);
	printf("long long int max: %Ld\n", LLONG_MAX);
	printf("unsigned long long int max: %Lu\n", ULLONG_MAX);
	printf("\n");

	printf("short int min: %d\n", SHRT_MIN);
	printf("short int max: %d\n", SHRT_MAX);
	printf("unsigned short int max: %u\n", USHRT_MAX);
	printf("\n");
}
