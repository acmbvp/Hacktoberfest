##### FUNCTION DEFINATION #####
def solution(n, q, operations):
    bitmask = [0] * n
    print("Bitmask = "+str(bitmask))
    sum = 0
    
    if q == 0:
        sum = 0
    else:
        ## Perform operations
        print("\nOperation Started....")
        for operation in operations:
            type, l, r = operation
    
            if type == 0:
                for i in range(l, r+1):
                    bitmask[i] = bitmask[i] ^ 1
                    
                print("Updated Bitmask = "+str(bitmask))
                
            elif type == 1:
                set_bit_count = 0
                for i in range(l, r+1):
                    if bitmask[i] == 1:
                        set_bit_count = set_bit_count + 1
                        
                sum = sum + set_bit_count
                print("Sum after query = "+str(sum))
        
        sum = sum % 1000000007
        
    return sum
    
if name == "main":
    ##### PREPARATION OF INPUT #####
    
    n = int(input("Enter No. of bits (n): "))
    # n = 5
    print("n = "+str(n))

    q = int(input("Enter No. of Operations (q): "))
    # q = 4
    print("q = "+str(q))

    # operations = [(0, 1, 3), (1, 1, 2), (0, 0, 4), (1, 3, 4)]
    
    operations=[]
    for i in range(q):
        operations.append(tuple(map(int, input("Operation "+str(i+1)+" = ").split(" "))))
    
    print("Operations = "+str(operations))
    
    sum = solution(n, q, operations)
    
    print("\nSum of all queries = "+str(sum))
