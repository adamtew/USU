# Sequences
# Lists, strings tuples, etc
	# Strings are immutable, lists are mutable (lists can change, strigns can't)
	# You don't have to specify the type in a list

list3 = [1, 'a', 'violin', 3.15, "math"]
print list3

# nested lists
list4 = [1, list3, [5, 6], "something", 5, 6, ["somethingElse"], list3]
print list4

x = list("abcdefg")
print x

y = list(list4)
print y

# Sequencing operations
	# Indexing
	# You can go backwards as well as forward

print list3[0], list3[-1]

	# membership
	# keyword in

print 1 in list3
print 1 not in list3

print list3 in list4
print [5, 6] in list4

	# Concatenation

z = x + y
print y

	# Multiplication
a = [1, 2]
b = [3, 4]

	# slicing
print list3[0:5]
print list4[4:5]
print list3[:]

	# Length, Minimum, Maximum
print len(list3)
print len(list4)
print min(list3)
print max(list4)

	# Multi-Dimensional Lists

	# Deleting elements
print "deleting elements: "
print list4[5]
del list4[5]
print list4[5]

	# Append
print "Append list"
print list3[:]
list3.append('abcdef')
print list3[:]

	# Extend
print "Extend"
print list3[:]
list3.extend('abcdefg')
print list3[:]

	# Count and index
print list3.count('a')
print list3.index('a', 1, 2)

	# Remove or reverse
print list3
list3.remove('a')
print list3
# list3.reverse('a')
# print list3

	# Function parameters
# position is what we've been using normally
# we now have keyword parameters

	# Positional
def setLoc(rX, rY):
	x = rX
	y = rY
	return x, y

def printName(rName):
	print rName

printName("adam")

def setName(rFist, rLast, rMiddle=""):
	print rLast, rFist, ",", rMiddle, "."

setName("Adam", "Tew", "James")

	# *operator is a "Collection operator" to send in multiple arguments
def values(rValues, *rSum):
	print sum
	print rValues

values(5, 'a','b')

	# Scope
x = 10
def f(x):
	x = x + 5
	return x

print x
print f(x)
print x

def f(z):
	global x
	x = 20
	return x

print x
print f(x)
print x













