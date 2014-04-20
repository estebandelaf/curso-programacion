#!/usr/bin/env python 
  
def fib(n): 
    if n == 0: 
        return 0
    if n == 1: 
        return 1
    return fib(n-1) + fib(n-2) 
  
if __name__ == '__main__': 
    n =int(input("n = ")) 
    fibonacci = fib(n) 
    print('Fibonacci de orden: ',n) 
    print(fibonacci) 
