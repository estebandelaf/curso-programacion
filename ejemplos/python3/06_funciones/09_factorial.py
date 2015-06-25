def factorial(n) :
    f = 1
    for i in range (2,n+1) :
        f *= i
    return f

def factorial2(n) :
    f = 1
    while n != 0 :
        f *= n
        n -= 1
    return f

print(factorial(3))
print(factorial(0))
print(factorial2(3))
print(factorial2(0))
