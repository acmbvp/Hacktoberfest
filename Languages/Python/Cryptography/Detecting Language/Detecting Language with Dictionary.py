# -*- coding: utf-8 -*-
"""
Created on Sat May 11 16:50:24 2019

@author: jmat
"""
ALPHABET= ' ABCDEFGHIJKLMNOPQRSTUVWXYZ'
ENGLISH_WORDS= []

def get_data():
    dictionary = open("english_words.txt","r")
    for word in dictionary.read().split('\n'):
        ENGLISH_WORDS.append(word)
