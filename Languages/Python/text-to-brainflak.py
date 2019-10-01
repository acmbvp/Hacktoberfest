# This program takes some text and prints a brainflak program that will output the text

cache = {}

def generate_number(num, height, level = 0, output = False): # Idea to use Stack Height inspired by Jo King
	if output: print(" " * level + str(num) + " " + str(height))
	if (num, height) in cache: return cache[(num, height)]
	if num == 0: return ""
	if num < 0: return "[" + generate_number(-num, height, level + 1, output) + "]"
	if num == height: return "[]"
	value = min((["[]" + generate_number(num - height, height, level + 1, output)] if height > num * 2 and abs(num - height) < num else []) + ["()" + generate_number(num - 1, height, level + 1, output)] + ["(%s)%s{}" % (generate_number(num // i, height, level + 1, output), "({})" * (i - 2)) for i in range(2, num) if num % i == 0], key = len)
	cache[(num, height)] = value
	return value

generate_number(256, 0, 0, False)

def generate_string(array):
	string = ""
	last = 0
	for height, num in enumerate(array):
		string = min("(" + string + generate_number(num - last, height) + ")", "<" + string + ">" + "(" + generate_number(num, height) + ")", key = len)
		last = num
	return string

a = lambda s: generate_string(list(map(ord, s)))

i = sys.stdin.read()
j = i[::-1]

print(min(a(j), a(i) + "{({}<>)<>}<>", key = len))
