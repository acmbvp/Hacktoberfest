#include <stdio.h>
#define ABS(x) ((x) < 0 ? -(x): (x))
double sqroot(double y) {
	double c = y / 2;
	if(y < 0)
		return -1;
	while(ABS(c * c - y) > 0.0001)
		c = (c + y / c) / 2;
	return c;
}
int main() {
	double x;
	scanf("%lf", &x);
	y = sqroot(x);
	if(y == -1) 
		printf("Bad input value\n");	
	else	
		printf("%lf\n", y);
}
