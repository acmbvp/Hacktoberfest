# -*- coding: utf-8 -*-
"""
Created on Sat May 11 11:57:28 2019

@author: jmat
"""

ALPHABET=" ABCDEFGHIJKLMNOPQRSTUVWXYZ"

def ceasar_crack(cipher_text):
    
    
    for key in range(len(ALPHABET)):
        plain_text=""
        for c in cipher_text:
            index=ALPHABET.find(c)
            index=(index-key)%len(ALPHABET)
            plain_text=plain_text+ALPHABET[index]
        print("With key " + str(key)+ ", the result is " +  str(plain_text))

if __name__ =="__main__":
    encrypted="VJKUBKUBCBOGUUCIG"
    ceasar_crack(encrypted)
