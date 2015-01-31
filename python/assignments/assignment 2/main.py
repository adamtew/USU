def derivative(f, x, h):
	return (f(x + h) - f(x - h)) / (2.0*h)

def quadratic(x):
	return 2 * x * x - 5 * x + 1

def solve(f, x0, h):
	lastX = x0
	nextX = lastX + 10 * h
	while(abs(lastX - nextX) > h):
		newY = f(nextX)
		print "f(", nextX, ") = ", newY
		lastX = nextX
		nextX = lastX - newY / derivative(f, lastX, h)
	return nextX

xFound = solve(quadratic, 5, 0.01)
print "solution: x = ", xFound

def quadratic1(x):
	return (x * x * x) - (2 * x) - 5

def quadratic2(x):
	return 3 * (x * x) - 2

# x = (3(x * x) - 2)

xFound = solve(quadratic1, quadratic2, 2)
print "solution: x = ", xFound