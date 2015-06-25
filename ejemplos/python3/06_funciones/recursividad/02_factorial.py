"""
Definición de factorial por inducción (para números positivos):
- Caso base: 0! = 1
- Caso general: n! = n * (n-1)!
"""

def factorial(n) :
    if n == 0 :
        return 1
    return n * factorial(n-1)

print(factorial(3))
print(factorial(0))
