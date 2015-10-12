# Problem 3           (3 Points)
# Write a python program that will generate five random passwords each time it is run with the following structure: 
# (one capital lette'r', followed by six small letters, followed by one number) Use one function to generate all of the 
# letters and numbers randomly. Print the generated passwords Hint: Think about using random.choice

# Sample run: 
# >>> 
# ('Password 1, 'Jjdobgq4') 
# ('Password 2, 'Shoigeo2') 
# ('Password 3, 'Vyfauff7') 
# ('Password 4, 'Clgthbz4') 
# ('Password 5, 'Fqkszms3')
import random

def generate_password():
	
	capLetters = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',' K', 'L', 'M','N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
	lowLetters = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
	numbers = ['1', '2', '3', '4', '5', '6', '7', '8', '9', '0']
	for x in xrange(5):
		index = 'Password ' + `x`
		n = []
		n.append(random.choice(capLetters))
		for x in xrange(6):
			n.append(random.choice(lowLetters))
		n.append(random.choice(numbers))
		password = ''.join(n)
		print index, password

generate_password()

