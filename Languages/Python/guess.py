import random
while True:
    x = 0
    word = random.randint(0,20)
    user = int(input("Pick a number from 0 to 20: "))
    if user == word:

        print("This is the right number")
    elif user > word:

        print("The number is too high")
    else:

        print("The number is too low")
    x += 1