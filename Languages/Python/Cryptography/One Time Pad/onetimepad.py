from random import randint
import matplotlib.pylab as plt

#we need the alphabet because we convert letters into numerical values to be able to use
#mathematical operations (note we encrypt the spaces as well)
ALPHABET = ' ABCDEFGHIJKLMNOPQRSTUVWXYZ'

#one time pad (OTP) encryption
def encrypt(plain_text, key):

	#convert the letters to uppercase
	plain_text = plain_text.upper()
	cipher_text = ''

	#consider all the plain_text letters: enumerate returns the item + it's index
	for index, char in enumerate(plain_text):
		#the value with which we shift the given letter
		key_index = key[index]
		#the given letter in the plain_text
		char_index = ALPHABET.find(char)
		#encrypted letter = char's value in the plain_text + random value (+using mod26)
		cipher_text += ALPHABET[(char_index+key_index)%len(ALPHABET)]

	return cipher_text

#decrypting the one time pad (OTP)
def decrypt(cipher_text, key):

	plain_text = ''

	for index, char in enumerate(cipher_text):
		key_index = key[index]
		char_index = ALPHABET.find(char)
		plain_text += ALPHABET[(char_index-key_index)%len(ALPHABET)]

	return plain_text

#generating the random sequence (it is a pseudo-random sequence!!!)
def random_sequence(plain_text):

	#we store the random values in a list
	random_sequence = []

	#generating as many random values as the number of characters in the plain_text
	#size of the key = size of the plain_text
	for rand in range(len(plain_text)):
		random_sequence.append(randint(0,len(ALPHABET)))

	return random_sequence

def frequency_analysis(plain_text):

	#the text we analyise
	plain_text = plain_text.upper()

	#we use a dictionary to store the letter-frequency pair
	letter_frequency = {}

	#initialize the dictionary (of course with 0 frequencies)
	for letter in ALPHABET:
		letter_frequency[letter] = 0

	#let's consider the text we want to analyse
	for letter in plain_text:
		#we keep incrementing the occurence of the given letter
		if letter in ALPHABET:
			letter_frequency[letter] += 1

	return letter_frequency

#plot the histogram of the letter-frequency pairs

def plot_distribution(letter_frequency):
	centers = range(len(ALPHABET))
	plt.bar(centers, letter_frequency.values(), align='center', tick_label=letter_frequency.keys())
	plt.xlim([0,len(ALPHABET)-1])
	plt.show()

if __name__ == "__main__":

	plain_text = "Shannon defined the quantity of information produced by a source for example the quantity in a message by a formula similar to the equation that defines thermodynamic entropy in physics. In its most basic terms Shannons informational entropy is the number of binary digits required to encode a message. Today that sounds like a simple even obvious way to define how much information is in a message. In 1948, at the very dawn of the information age, this digitizing of information of any sort was a revolutionary step. His paper may have been the first to use the word bit, short for binary digit. As well as defining information, Shannon analyzed the ability to send information through a communications channel. He found that a channel had a certain maximum transmission rate that could not be exceeded. Today we call that the bandwidth of the channel. Shannon demonstrated mathematically that even in a noisy channel with a low bandwidth, essentially perfect, error-free communication could be achieved by keeping the transmission rate within the channel's bandwidth and by using error-correcting schemes: the transmission of additional bits that would enable the data to be extracted from the noise-ridden signal. Today everything from modems to music CDs rely on error-correction to function. A major accomplishment of quantum-information scientists has been the development of techniques to correct errors introduced in quantum information and to determine just how much can be done with a noisy quantum communications channel or with entangled quantum bits (qubits) whose entanglement has been partially degraded by noise."

	print("Original message: %s" % plain_text)
	key = random_sequence(plain_text)
	cipher_text = encrypt(plain_text, key)
	print("Encrypted message: %s" % cipher_text)
	decrypted_text = decrypt(cipher_text, key)
	print("Decrypted message: %s" % decrypted_text)

	plot_distribution(frequency_analysis(cipher_text))
