# Python program to check if the number is a strong number or not.

total=0
num=int(input("Enter a number:"))
temp=num
while(num):
    i=1
    f=1
    r=num%10
    while(i<=r):
        f=f*i
        i=i+1
    total=total+f
    num=num//10
if(total==temp):
    print(temp," is a strong number")
else:
    print(temp," is not a strong number")
