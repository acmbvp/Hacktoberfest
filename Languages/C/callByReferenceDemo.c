//call by reference demo in c
#include <stdio.h>
void add_sub(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int main()
{
    int a = 4, b = 3;
    printf("the values of a and b are %d and %d respectively\n", a, b);
    add_sub(&a, &b);
    printf("the values of a and b are %d and %d respectively\n", a, b);
    return 0;
}