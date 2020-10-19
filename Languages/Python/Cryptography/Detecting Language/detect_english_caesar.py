#we need the alphabet because we convert letters into numerical values to be able to use
#mathematical operations (note we encrypt the spaces as well)
ALPHABET = ' ABCDEFGHIJKLMNOPQRSTUVWXYZ'
#we store the english words in a list (maybe a dictionary would be better)	
ENGLISH_WORDS = []

#load the english words
def get_data():
	
	#let's load all the english words from a .txt file
	dictionary = open("english_words.txt","r")

	#initialize the ENGLISH_WORDS list with the words present in the file
	#every word is in a distinct line so that why we have to split('\n')
	for word in dictionary.read().split('\n'):
		ENGLISH_WORDS.append(word)
		
	dictionary.close()
	
#count the number of english words in a given text
def count_words(text):

	#upper case letters are needed
	text = text.upper()
	#transform the text into a list of words (split by spaces)
	words = text.split(' ')
	#matches counts the number of english words in the text
	matches = 0

	#consider all the words in the text and check whether the given word is english or not
	for word in words:
		if word in ENGLISH_WORDS:
			matches = matches + 1
			
	return matches

#decides whether a given text is english or not	
def is_text_english(text):
		
	#number of english words in a given text
	matches = count_words(text)

	#you can define your own classification algorithm
	#in this case the assumption: if 80% of the words in the text are english words then
	#it is an english text
	if (float(matches) / len(text.split('\n'))) * 100 >= 80:
		return True
		
	#not an english text
	return False

#cracking the caesar encryption algorithm with brute-force
def caesar_crack(cipher_text):

	#we try all the possible key values so the size of the ALPHABET
	for key in range(len(ALPHABET)):
	
		#reinitialize this to be an empty string
		plain_text = ''
		
		#we just have to make a simple caesar decryption
		for c in cipher_text:
			index = ALPHABET.find(c)
			index = (index-key)%len(ALPHABET)
			plain_text = plain_text + ALPHABET[index]
			
		#print the actual decrypted string with the given key
		if is_text_english(plain_text):
			print("We have managed to crack Caesar cipher, the key is: %s, the message is %s" % (key,plain_text))
	
if __name__ == "__main__":
	
	get_data()
	
	encrypted = 'VJKUBKUBCBOGUUCIG'
	caesar_crack(encrypted)