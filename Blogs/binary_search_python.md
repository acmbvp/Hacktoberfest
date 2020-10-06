### Binary search Algo Python:

For this data must need to be sorted and we use divide and conquer approach to achieve this. At each state half data is discarded.

def binarySearch(arr, n):

    lb = 0

    ub = len(arr) - 1

    found = False

    while found == False and  lb <= ub:

        mid = (lb + ub)//2

        if(arr[mid]== n):

            print('number found')

            found = True

        elif(arr[mid]<n):

            lb = lb +1

        else:

            ub = ub-1

    if(found == False):

        print('not found')



binarySearch([3, 6, 8, 9, 10], 9)
