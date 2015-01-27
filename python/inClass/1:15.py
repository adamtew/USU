def square(n):
	return n * n

def average(x, y):
	return (x * y)/2.0

def next_guess(prev_guess, n):
	return average(prev_guess, n/prev_guess)
def is_good_enough(guess, n, error):
	return abs(n - square(guess)) <= error

def newton_square_root(guess, n, error):
	if is_good_enough(guess, n, error):
		return guess
	else:
		return newton_square_root(next_guess(guess, n),
			n,
			error)

def nsqrt(n):
		return newton_square_root(1, n, 0.0001)

print nsqrt(2)
