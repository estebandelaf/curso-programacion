"""
Ejemplo de input.txt
4
5.5
3.9
6.2
"""
suma = 0
numeros = 0
archivo = open ("input.txt")
for linea in archivo :
    suma += float(linea)
    numeros += 1
archivo.close()
promedio = round(suma/numeros, 1)
print (promedio)
 
