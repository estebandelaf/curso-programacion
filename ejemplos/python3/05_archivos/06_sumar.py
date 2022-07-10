suma = 0
fd = open("input.txt")
for linea in fd :
    numero = float(linea.strip())
    suma += numero
fd.close()
print(suma)

