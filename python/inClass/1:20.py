# Numbers, Strings, Lists, Tuples, Dictionaries, Files

# Numbers:
# Integers go from [sys.maxint-1, sys.maxint]
print hex(1024)

print oct(1024)
print 0112
print oct(74)

print 1.0e2

# Complex numbers
import cmath
print 1j

# Numeric Operators
x = 5
y = 7
print x + y
print x - y
print x * y
print x / y
print x // y # floor operator
print x % y
print -x 
print x ** y

# __future__ this is the syntax for some of their future imports
# from __future__ import division

# Standard functions

print abs(x)
print int(x)
print long(x)
print float(x)
# print complex(x, i)

# Strings
# Can use "" Or ''
# You can embed strings in other strings like so "Something 'emedded'"
# Escape characters \"
h = 'hello'
w = "world"

print h + " " + w


print str(h)
print repr(h)

# Raw strings you prefix a string with a lowercase r
lmnop = r"Something\'\'\'\'\'\'\'\''\""
print lmnop


lmnop = "Something else"
print lmnop
print lmnop[0] + lmnop[1] + lmnop[2] + lmnop[3]
# lmnop[0] = 'g' does not work because the character is immutable


for x in range(1, 5):
	print "Item: ", x

while x > 10:
	print "%d" %x
	x += 1

x, y = 5, 6
print "Someone out there is %d years old" %y
x, y = y, x
print "Someone out there is %d years old" %y


import string
print string.upper(lmnop)

print h.upper()
print "Hello World".upper()

print "  I dislike white space      ".strip()

# print h.capwords()

knight = ['k', 'n', 'i', 'g', 'h', 't']

myStr = '' ##string to be built
for ch in knight:
	myStr += ch

print myStr

print 'chars = ', knight
print 'myStr = ', myStr

knight = ['k', 'n', 'i', 'g', 'h', 't']
myOtherString = ''.join(knight)
print myOtherString


text = '''This is how You will Write Things 
In multiple lines in Python'''

print text

print text.find('is')
print (text.split(' ')[0])[0]
print text.split('\n')
print text.replace('\n', '')
# print "this is a beautiful day!".repalce('beautiful', 'dreary')









