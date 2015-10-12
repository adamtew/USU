# if n is prime and a is positive less than n then a ^ n % n == a % n
import random
random.seed()

def is_fermat_prime(n, ntrials):
	for i in range(0, ntrials):
		if n > 1:
			a = random.randint(1, n - 1)
		else:
			return False
		if(a**n % n != a):
			return (a**n % n == a)
	return (a**n % n == a)
		
print is_fermat_prime(2, 5)

def find_fermat_primes(n, ntrials, primes=[]):
	if not n:
		return primes
	for i in range(0, ntrials):
		if n[0] > 1:
			a = random.randint(1, n[0] - 1)
		else:
			return find_fermat_primes(n[1:], ntrials, primes)
		if(a**n[0] % n[0] != a):
			return find_fermat_primes(n[1:], ntrials, primes)
	primes.append(n[0])
	return find_fermat_primes(n[1:], ntrials, primes)

x = []
for i in range(-5, 100):
	x.append(i)

print find_fermat_primes(x, 10)

