##Make sure to run with Python3 . Python2 will show issues
from math import sqrt
from math import floor

def is_prime(num):

	#numbers smaller than 2 can not be primes
	if num<=2: return False

	#even numbers can not be primes
	if num%2==0: return False

	#we have already checked numbers < 3
	#finding primes up to N we just have to check numbers up to sqrt(N)
	#increment by 2 because we have already considered even numbers
	for i in range(3,floor(sqrt(num)),2):
		if num%i==0:
			return False

	return True

if __name__ == "__main__":

	print(is_prime(99194853094755497))
