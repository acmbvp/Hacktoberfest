def factorialNum(num):
    """Python program to find the factorial of a number provided by the user.

    Args:
        num (Int): Input an integer 

    Returns:
        Int: Return a number which is a factorial of the input
    """    
    factorial = 1
    # check if the number is negative, positive or zero
    if num < 0:
       print("Sorry, factorial does not exist for negative numbers")
    elif num == 0:
       print("The factorial of 0 is 1")
    else:
       for i in range(1,num + 1):
           factorial = factorial*i
       print("The factorial of",num,"is",factorial)
