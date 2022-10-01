# LANGUAGE: Python
# AUTHOR: Soudip Das
# GITHUB: front-runner-sd

import random as r
import string
size = int(input("Enter the size of the password (size should be >8): "))
if size <= 7:
    print("try again...")
else:
    num_part=int(input("How many numbers do you want in the password (should be less than size/3 ): "))
    sp_char=int(input("How many special charecter you want in the password (should be less than size/3 ): "))
    l1=[]
    v=size-num_part-sp_char-2
    if v<=1:
        print("Invalid input...")
    else:    
        for x in range(0,v) :
            l1.append(r.choice(string.ascii_lowercase))

        for x in range(0,2) :
            l1.append(r.choice(string.ascii_uppercase))

        for x in range(0,num_part):
            l1.append(r.choice(string.digits))

        sp_char_part = ['!', '@', '#', ':', '%', '&', '^', '*', '?', '_']
        for x in range(0,sp_char):
            l1.append(r.choice(sp_char_part))

        r.shuffle(l1)
        
        c=""
        for ele in l1:
            c+=ele
        print(f"\nThe best password for you will be : {c}\n")
        dict1 = {"a": "apple ", "b": "box ", "c": "cat ", "d": "disco ", "e": "egg ", "f": "fire ", "g": "good ", "h": "home ", "i": "iphone ", "j": "jam ", "k": "kick ", "l": "large ", "m": "music ", "n": "new ", "o": "orange ", "p": "park ", "q": "queen ", "r": "run ", "s": "star ", "t": "tokyo ", "u": "usa ", "v": "visa ", "w": "winter ", "x": "xbox ", "y": "yoga ", "z": "zip ",
             "A": "Apple ", "B": "Box ", "C": "Cat ", "D": "Disco ", "E": "Egg ", "F": "Fire ", "G": "Good ", "H": "Home ", "I": "Iphone ", "J": "Jam ", "K": "Kick ", "L": "Large ", "M": "Music ", "N": "New ", "O": "Orange ", "P": "Park ", "Q": "Queen ", "R": "Run ", "S": "Star ", "T": "Tokyo ", "U": "Usa ", "V": "Visa ", "W": "Winter ", "X": "Xbox ", "Y": "Yoga ", "Z": "Zip ",
             }
        phrase_list=[]
        for x in c:
            if(x in dict1):
                word=dict1.get(x)
                phrase_list.append(word)
            else:            
                phrase_list.append(x)
                phrase_list.append(" ")
        phrase = ""
        for ele in phrase_list:
            phrase+=ele

        print(f"You can remind this password by ->  {phrase}")