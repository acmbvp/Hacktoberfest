import random

def Random_String_Generator(length):   
    key = "" 
    
    while len(key)!=length:
        i = random.randint(1,255)
        j = random.randint(1,255)
        
        s = (i*j)%128
        
        if s<33:
            s = random.randint(33,128)
        
        key += str(chr(s))

    print key
    
length = input("Enter Length: ")

Random_String_Generator(length)
