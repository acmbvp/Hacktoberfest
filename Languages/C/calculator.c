#include<stdio.h>
int main()
{
    printf("Menu: \n 1.Addition \n2.Subtraction \n3.Multiplication \n4.Division");
    int choice;
    int n,number , sum , difference , multiply , dividend , divisor,check;
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            {
                     printf("\nEnter the amount of numbers to be added :");
                     scanf("%d",&n);
                     sum=0;
                     while(n--)
                     {
                        printf("\nEnter number :");
                        scanf("%d",&number);
                        sum = sum + number;
                     }
                     printf("\nThe sum is : %d",sum);
                     break;
                   }
       case 2:
           {
                    printf("\nEnter the amount of numbers to be subtracted in order :");
                     scanf("%d",&n);
                     check=n;
                     difference =0;
                     while(n>0)
                     {
                        printf("\nEnter number :");
                        scanf("%d",&number);
                        if(n==check)
                        difference = difference + number;
                        else
                            difference = difference - number;
                        n--;
                     }
                     printf("\nThe difference is : %d",difference);
                     break;

                   }
        case 3:
            {
                       printf("\nEnter the amount of numbers to be multiplied :");
                     scanf("%d",&n);
                     multiply= 1;
                     while(n--)
                     {
                        printf("\nEnter number :");
                        scanf("%d",&number);
                        multiply = multiply * number;

                     }
                     printf("\nThe multiplication of numbers are : %d",multiply);
                     break;
         }
        case 4:
            {
               printf("Enter dividend : ");
               scanf("%d",&dividend);
               printf("Enter divisor : ");
               scanf("%d",&divisor);
               printf("\nQuotient is : %d",dividend / divisor);
               printf("\nRemainder is : %d",dividend % divisor);
               break;
            }
            default: printf("\nInvalid choice");
    }
    return 0;
}
