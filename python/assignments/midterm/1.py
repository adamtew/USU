# Problem 1                                                                                                  (3 points)
# Write a python program that reads an integer 'N' from the user and then calls a user defined function to compute and display the sum 
# of the numbers from N to (2 * N) if N is nonnegative. If N is a negative number, 
# then it's the sum of the numbers from (2 * N) to N. The starting and ending points are included in the sum.

# Sample run: >>>Enter number : 5 Sum : 45 Sample run: >>>Enter number : -4 Sum : -30 


# Hint: You should have only 1 loop to compute the sum; use the sign of N to determine the start point and
# the end point

# x = input("Enter Number: ")
x = 'string'

def myFunction(n):
	try:
		int(n)
		n = int(n)
		first = n
		if n > 0:
			for x in xrange(abs(n * 2)):
				n += x
			n -= first
		else:
			for x in xrange(abs(n * 2)):
				n -= x
			n -= first
	
		return int(n)
	except ValueError:
		return 'Not a number'

print myFunction(x)

