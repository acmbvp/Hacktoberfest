def insert_sort(a):  
    for i in range(1, len(a)): 
  
        k = a[i] 
        j = i-1
        while j >=0 and k < a[j] : 
                a[j+1] = a[j] 
                j -= 1
        a[j+1] = k 
a = [23, 11, 56, 34, 24, 12, 19, 8, 67, 54, 11] 
insert_sort(a) 
print ("Array after sorting is:") 
for i in range(len(a)): 
    print (a[i]) 
