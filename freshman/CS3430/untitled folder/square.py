def square(x):
	return x * x

def average(x,y):
	return (x + y) / 2

def eval_poly(a, b, c, x):
	return a * square(x) + b * x + e

l = "Something"


myList = [
	{'Category': {'Category': 'Books'}, 'Items': {'Item': 'Les Miserables'}},
	{'Category': {'Category': 'Books'}, 'Items': {'Item': 'Les Miserables'}},
	{'Category': {'Category': 'Books'}, 'Items': {'Item': 'Les Miserables'}},
	{'Category': {'Category': 'Books'}, 'Items': {'Item': 'Les Miserables'}} ]

print myList[0]["Items"]["Item"]

myDict = {'myList': myList}

print myDict["myList"][0]["Items"]["Item"]


bob = {'word': [1,2,3,4,5]}

print bob['word'][0]
