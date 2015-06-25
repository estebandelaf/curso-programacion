def cuenta_regresiva(n):
    print(n)
    if n != 1 :
        cuenta_regresiva(n-1)

def cuenta_regresiva2(n):
    print(n)
    if (n-2) >= 1 :
        cuenta_regresiva(n-2)

cuenta_regresiva(10)
cuenta_regresiva2(10)
