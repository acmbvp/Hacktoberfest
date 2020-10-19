import random

def generate_private_key(n,g):

	#random number for Alice where x<n-1
	x = random.randint(1,n)

	#random number for Bob where x<n-1
	y = random.randint(1,n)

	#calculate g^x mod n which is Alice's k1
	k1 = pow(g,x,n)
	#calculate g^y mod n which is Bob's k2
	k2 = pow(g,y,n)

	#if an attacker wants to get x and y (the private keys) which is the discrete
	#logarithm problem it is an exponentially slow process !!!
	print("Alice's private key %s"%(pow(k2,x,n)))
	print("Bob's private key %s"%(pow(k1,y,n)))

if __name__ == "__main__":

	#it should be a huge prime number
	n=37
	#g is the primitive root of n
	g=13

	#using Diffie-Hellman cryptosystem for generating private key (for DES and AES)
	generate_private_key(n,g)
