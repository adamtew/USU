def se(n):
	numbers = [];
	for x in range(2, n):
		numbers.append(x);
	print increment(numbers);
	return numbers

def increment(x, newX=[]):
	if not x:
		# print "base", newX;
		return newX;
	else:
		for a in range(x[0], len(x)):
			if a % x[0] == 0:
				print "a: ", a
				newX.append(x[a]);
				print list(set(x) - set(newX))
		# print "not base", x[0];
		 
		return increment(x[1:], newX);

def manipulate(x):
	x = int(x);
	x = se(x);
	x = str(x);
	return x;

# def step2(p):


print manipulate('30');

