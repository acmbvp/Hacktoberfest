# code to find sum of n numbers and squares of n numbers


def num_sum(x):
    sum = (x*(x+1))//2
    return sum


def sq_sum(x):
    sum = (x*(x+1)*(2*x+1))//6
    return sum


num = int(input("Enter the number\n"))
print()
print("What do you want to do:\n 1. Print sum of first n natural numbers\n 2. Print sum of squares of first n natural numbers")
print()
prompt = input("Enter your choice\n")
print()

if prompt == '1':
    ans = num_sum(num)
    print("Value of summation is: " + str(ans))
elif prompt == '2':
    ans = sq_sum(num)
    print("Value of summation is: " + str(ans))
