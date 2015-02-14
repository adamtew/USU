# Object Oriented Programming

# Constructors = def __init__():
# if you want to define default values you can
# 	def __init__(self, city="Logan"):
# 		self.city = city

# Polymorphism
# When you can use the same function on multiple types?

# Encapsulation
# If you want to hide a lot of the data from the user behind the scenes

# making something private __varName <--- this makes it private
# for a function you use def __funName
# When calling a private value you use the normal name Class.funName or Class.varName

# Inheritance
# basically you have parent classes and child classes
class A:
	def f(self):
		# print 'A\'sf.'
		print "something"

	def g(self):
		print 'A\'sg/'

class B(A):
	def g(self):
		print 'B\'sg.'

a = A()
print a.f
print a.g
print isinstance(a, A)
print isinstance(a, B)


b = B()
print b.f
print b.g
print isinstance(b, B)
print isinstance(b, A)

# 
# Starting PyGame
# 

import pygame
# pygame.ver







