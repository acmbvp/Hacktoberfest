# change the value for a different result
def fact(n):
   if n==1:
      return n
   else:
      return n*fact(n-1) 
num = 7
# uncomment to take input from the user
#num = int(input("Enter a number: "))
factorial = 1
# check if the number is negative, positive or zero
if num < 0:
   print("Sorry, factorial does not exist for negative numbers")
elif num == 0:
   print("The factorial of 0 is 1")
else:
   print("The factorial of",num,"is",fact(num))