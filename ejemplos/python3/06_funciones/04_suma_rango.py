def suma_rango(a,b) :
    suma = 0
    for i in range (a, b+1) :
        suma += i
    return suma
print(suma_rango(2,5))
print(suma_rango(2,3))
