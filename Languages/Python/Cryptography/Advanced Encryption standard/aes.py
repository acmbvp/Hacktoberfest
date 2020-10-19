from Crypto.Cipher import AES
from Crypto import Random
import binascii

#we can use the AES algorithm like this
#there are several modes (7 modes)
# 1.) ECB: "Electronic Code Book" -> we use AES on every 128 bits long plaintext block 
#		these blocks are independent of each other so we use AES separately on every block
# 2.) CBC: "Cipher Block Chaining" -> uses a chaining mechanism that causes
#		the decryption of a block of ciphertext to depend on all the preceding ciphertext blocks
#
#	THE PADDING PROBLEM
#		AES algorithm uses 128 bits long inputs: what if the plaintext is not divisible by 128?
#			~ in these cases we append some extra bits to the plaintext to be able to split			
#					the plaintext into 128 bits long chunks
#	
#		Padding modes: 
#			-> we can add extra bits: 100000 for example
#			-> we can add white-spaces to the plaintext
#			-> we can use CMS "Cryptographic Message Syntax"...pad with bytes all of the same value as the number of padding bytes

def append_space_padding(str, blocksize=128):
	pad_len = blocksize - (len(str) % blocksize)  
	padding = 'a'*pad_len
	return str + padding

def remove_space_padding(str, blocksize=128):
    
    pad_len = 0 
	
    for char in str[::-1]: 
        if char == 'a':
            pad_len += 1
        else:
            break

    str = str[:-pad_len]
   
    return str
	
def encrypt(plaintext, key):
	des = AES.new(key, AES.MODE_ECB)
	return des.encrypt(plaintext)

def decrypt(ciphertext, key):
	des = AES.new(key, AES.MODE_ECB)
	return des.decrypt(ciphertext).decode('UTF-8')

if __name__ == "__main__":

	#key is 128 bits = 16 bytes
	key = Random.new().read(16)
	print(key)
	plaintext = "This is the secret message we want to encrypt!"
	print(len(plaintext))
	plaintext = append_space_padding(plaintext)
	print(len(plaintext))
	print(plaintext)
	
	ciphertext = encrypt(plaintext,key)
	print(binascii.hexlify(bytearray(ciphertext)))
	
	decrypted = decrypt(ciphertext,key)
	decrypted = remove_space_padding(decrypted)
	print("Decrypted message:" ,decrypted)
	