#Python Script to print Rectangle Pattern
i=int(input())
j=int(input())
for a in range(i):
    for b in range(j):
        if a==0 or a==i-1 or b==0 or b==j-1:
            print("*",end=" ")
        else:
            print(" ",end=" ")
    print("")
