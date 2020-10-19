# -*- coding: utf-8 -*-
"""
Created on Sat May 11 13:09:34 2019

@author: jmat
"""

import matplotlib.pylab as plt

LETTERS=" ABCDEFGHIJKLMNOPQRSTUVWXYZ"

def frequency_analysis(cipher_text):
    #plain_text=plain_text.upper()
    
    letter_frequency= {}
    
    for letter in LETTERS:
        letter_frequency[letter]=0
    
    for letter in plain_text:
        if letter in LETTERS:
            letter_frequency[letter]+=1
    return letter_frequency

def plot_distribution(letter_frequency):
    centers=range(len(LETTERS))
    plt.bar(centers,letter_frequency.values() , align='center',tick_label=letter_frequency.keys() )
    plt.xlim([0,len(LETTERS)-1])
    plt.show()

def ceasar_crack(cipher_text):
    letter_frequency = frequency_analysis(cipher_text)
    print(letter_frequency)
    plot_distribution(letter_frequency)
    
if __name__ == "__main__":
    #plain_text="Shannon defined the quantity of information produced by a source-- "
    cipher_text="VJKUBKUBCBOGUUCIG"
    frequencies = frequency_analysis(cipher_text)
    plot_distribution(frequencies)
    print(de)
