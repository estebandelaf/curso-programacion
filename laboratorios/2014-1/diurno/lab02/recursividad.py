#!/usr/bin/python
# -*- coding: utf8 -*-

def factorial (n) :
	if n<2 :
		return 1
	else :
		return (n * factorial(n-1))

print ('3! =', factorial(3))
print ('6! =', factorial(6))
