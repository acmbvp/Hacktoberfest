import random 

seed = random.randint(1,100)

while True:
    guess_number = int(input("enter your guessed number:"))

    if guess_number==seed:
        print("You won")
        break
    else:
        print("Try again diff is:",seed-guess_number)
        continue


