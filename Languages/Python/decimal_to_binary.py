def DecimalToBinary(num): 
      
    if num > 1: 
        DecimalToBinary(num // 2) 
    print(num % 2, end = '') 
  
# Driver Code 
if __name__ == '__main__': 
      
    # decimal value input

    dec_val = int(input())
      
    # Calling function 
    DecimalToBinary(dec_val) 