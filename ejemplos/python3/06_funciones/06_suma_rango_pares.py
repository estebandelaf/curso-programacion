def suma_rango_pares(a,b) :
    suma = 0
    if a%2 == 1 :
        a += 1
    for i in range (a, b+1, 2) :
        suma += i
    return suma
print(suma_rango_pares(0,6)) # 12
print(suma_rango_pares(3,6)) # 10
