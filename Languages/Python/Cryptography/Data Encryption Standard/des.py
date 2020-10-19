from Crypto.Cipher import DES
import binascii

#we can use the DES algorithm like this
#there are several modes (7 modes)
# 1.) ECB: "Electronic Code Book" -> we use DES on every 64 bits long plaintext block 
#		these blocks are independent of each other so we use DES separately on every block
# 2.) CBC: "Cipher Block Chaining" -> uses a chaining mechanism that causes
#		the decryption of a block of ciphertext to depend on all the preceding ciphertext blocks
#
#	THE PADDING PROBLEM
#		DES algorithm uses 64 bits long inputs: what if the plaintext is not divisible by 64?
#			~ in these cases we append some extra bits to the plaintext to be able to split			
#					the plaintext into 64 bits long chunks
#	
#		Padding modes: 
#			-> we can add extra bits: 100000 for example
#			-> we can add white-spaces to the plaintext
#			-> we can use CMS "Cryptographic Message Syntax"...pad with bytes all of the same value as the number of padding bytes

def append_space_padding(str, blocksize=64):
  pad_len = blocksize - (len(str) % blocksize)  
  padding = 'a'*pad_len
  return str + padding

def remove_space_padding(str, blocksize=64):
    
    pad_len = 0 
	
    for char in str[::-1]: 
        if char == 'a':
            pad_len += 1
        else:
            break

    str = str[:-pad_len]
   
    return str
	
def encrypt(plaintext, key):
	des = DES.new(key, DES.MODE_ECB)
	return des.encrypt(plaintext)

def decrypt(ciphertext, key):
	des = DES.new(key, DES.MODE_ECB)
	return des.decrypt(ciphertext).decode('UTF-8')

if __name__ == "__main__":

	key = "secretaa"
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
	