#include <stdio.h> 
  
int main() 
{ 
int n, i, flag = 1; 
printf("Enter a number: \n");  
scanf("%d", &n); 
for (i = 2; i <= sqrt(n) / 2; i++) { 
if (n % i == 0) { 
flag = 0; 
break; 
} 
} 
if (flag == 1) { 
printf("%d is a prime number", n); 
} 
else { 
printf("%d is not a prime number", n); 
} 
return 0; 
} 
