#!/usr/bin/env python

# LANG: Python 3
# AUTHOR: Sebastian Alejandro
# GITHUB: kaewhyes

word = "bottle"
beer = 99

for x in range(beer, -1,-1):

    plural = ""

    if x == 1:
        plural = word
    else:
        plural = word + "s"

    print(str(x) + " " + plural + " of beer on the wall, " + str(x) + " " + plural + " of beer")

    if x > 0:
        print("Take one down, pass it around, " + str(x) + " " + plural + " of beer on the wall!")
    else:
        print("You're out of beer, get some more!")
