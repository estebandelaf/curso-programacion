fd = open("input.txt")
for linea in fd :
    lista = linea.strip().split(" ")
    suma = 0
    for numero in lista :
        suma += int(numero)
    print(suma)
fd.close()

