# operators for comparing stuff

x = 'a', 'b'
y = 1, 2

print cmp(x, y)

print cmp(1, 2)

print cmp(2, 1)

print cmp(1, 1)

print cmp('a', 'b')

def neg_cmp(x, y):
	return -cmp(x,y)

z = [1, 2, 3, 4, 5]


z.sort(neg_cmp)
print z


print cmp(5, 25)


# Loops
# while, for, foreach

x = 1
while x <= 100:
	print x
	x += 1

# name = ''

# while not name:
# 	name = raw_input('please enter a name: ')

# print 'Hello, %s!' %name
# print "Hello", name
lst = ['h', 'e', 'l', 'l', 'o']

for l in lst:
	print l


# This does things in a range.. Kind of interesting
print range(5,10)
print range(1, -9, -3)

# Range uses a lot of memory, so you sometimes want to use xrange, because it takes less memory
rng = xrange(0, 10)

for x in rng:
	print x

for n in rng:
	for x in range(2, n):
		if n % x == 0:
			print n, "equals: ", x
			break


# zipping things matches stuff together... kinda weird
names = ['a', 'b', 'c', 'd']
numbs = [1, 2, 3, 4]

# print zip(['a', 1],['b', c])

# libraries are basically a mutablepair of things.
# the keys will be immutable

dict = {'one':1}

# Libraries are basically JSON objects

box = {'first':2, 'second':3}
# box = dict({'first':2, 'second':3})

print box

box1 = box.copy()
print box1

from copy import deepcopy
box2 = box.deepcopy()
# print box[1]




















