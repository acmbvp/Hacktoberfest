# -*- coding: utf-8 -*-
"""
Created on Sat May 11 11:25:36 2019

@author: jmat
"""
ALPHABET=" ABCDEFGHIJKLMNOPQRSTUVWXYZ"
KEY=3

def ceasar_encrypt(plain_text):
    
    cipher_text=""
    plain_text=plain_text.upper()
    
    for c in plain_text:
        index=ALPHABET.find(c)
        index=(index+KEY)%len(ALPHABET)
        cipher_text=cipher_text +ALPHABET[index]
        
    return cipher_text

def ceasar_decrypt(cipher_text):
    
    plain_text=""
    
    for c in cipher_text:
        index=ALPHABET.find(c)
        index=(index-KEY)%len(ALPHABET)
        plain_text=plain_text+ALPHABET[index]
        
    return plain_text

if __name__ =="__main__":
    encrypted=ceasar_encrypt("This is an example")
    print(encrypted)
    decrypted=ceasar_decrypt(encrypted)
    print(decrypted)

