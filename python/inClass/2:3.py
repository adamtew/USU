# Write a function str_freq(s) that takes a string s and returns a dictionary that maps every character in s to its frequency in s.

# >>> d = str_freq('aabc')
# >>> d
# {'a': 2, 'c': 1, 'b': 1}
# >>> d1 = str_freq('ab c ee!')
# >>> d1
# {'a': 1, ' ': 2, 'c': 1, 'b': 1, 'e': 2, '!': 1}

def str_freq(s):
	d = {}
	for e in s:
		if d.has_key(e):
			d[e] += 1
		else:
			d[e] = 1
	return d

print str_freq('aabc')

# Write a list comprehension that permutes even numbers from 0 through 4 with odd numbers from 0 through 4. 
# >>>output
# >>>[(0, 1), (0, 3), (2, 1), (2, 3), (4, 1), (4, 3)]
even = [0, 1, 2, 3, 4]
odd = [1, 3]
bob = [(x,y) for x in range(5) if x % 2 ==0 for y in range(5) if y % 2 == 1]
print bob


# Write a list comprehension that reduces a 5 x 5 integer matrix to the sum of its rows.

# For example:
# >>> m = [[i+j for i in xrange(5)] for j in xrange(1, 6)]
# >>> m
# [[1, 2, 3, 4, 5], [2, 3, 4, 5, 6], [3, 4, 5, 6, 7], [4, 5, 6, 7, 8], [5, 6, 7, 8, 9]]
# >>> [your list comprehension that references m]
# [15, 20, 25, 30, 35]
m = [[i+j for i in xrange(5)] for j in xrange(1, 6)]
print m
n = [sum(r) for r in m]
print n


# Write a function that takes an arbitrary number of key-value pairs and returns the maximum value.

# For example:
# >>> max_val(x1=1, x2=3, x3=2)
# 3
# >>> max_val(x1=1, x2=50, x3=100, x4=4, x5=5, x6=7, x7=6)
# 100

def maxVal(**rVals):
	return max([v for v in rVals.itervalues()])


print maxVal(x1=1, x2=2, x3=3, x4=4)



# Objects in Python
__metaclass__ = type #<---- just for backwards compatability

class Person:

	def __init__(self):
		name = "Adam"
		age = 25
	# Properties
	name = ""
	age = 0

	# methods
	def setName(self, x): #self is basically the "this" of Python
		self.name = x

	def setAge(self, x):
		self.age = x

	def printName(self):
		print self.name

	def printAge(self):
		print self.age


adam = Person()
adam.setName("Adam")
adam.setAge(25)
adam.printName()
adam.printAge()

# self does not have to be passed as a parameter.
# __init__(self): is the constructor














