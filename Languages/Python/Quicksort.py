def quickSort(list4,start,end):
    if start>=end:
        return
    pivot = end-1
    pivot = changePivot(list4,start,pivot)
    quickSort(list4,start,pivot)
    quickSort(list4,pivot+1,end)
    return list4

# function to change the pivot

def changePivot(list4, start, pivot):
    j=start
    for i in range(start,pivot):
        if list4[i]<list4[pivot]:
            swap(list4,i,j)
            j=j+1
    swap(list4,j,pivot)
    return j

# swaping of two elements
def swap(list2,i,j):
    temp = list2[i]
    list2[i]=list2[j]
    list2[j]=temp


# input by user
n = int(input("Enter number of elemenys in list\n"))
list1=[]
for i in range(n):
    elem = int(input())
    list1.append(elem)

print("List after quick sorting: ",quickSort(list1,0,len(list1)))     # function call
