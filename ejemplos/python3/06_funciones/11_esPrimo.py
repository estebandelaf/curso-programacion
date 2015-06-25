def esPrimo(n) :
    for d in range(2, n) :
        if n%d == 0 :
            return False
    return True

print(esPrimo(7))
print(esPrimo(9))
print(esPrimo(13))
print(esPrimo(15))
