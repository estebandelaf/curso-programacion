"""
Ejemplo de código que indica
si un número es par o impar
"""
n = int(input("Ingrese el número a verificar: "))
r = n % 2
if r == 0 : # ¿si resto es 0?
    print ("es par")
else : # si no (o sea si el if fue falso)
    print ("es impar")
