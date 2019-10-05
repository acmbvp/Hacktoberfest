# getMissingNo takes list as argument 
def getMissingNo(A): 
    n = len(A) 
    total = (n + 1)*(n + 2)/2
    sum_of_A = sum(A) 
    return total - sum_of_A 
  
# Driver program to test above function 
A = [1, 2, 4, 5, 6] 
miss = getMissingNo(A) 
print(miss) 
