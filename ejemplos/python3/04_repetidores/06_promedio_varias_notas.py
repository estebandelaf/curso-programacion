suma = 0
notas = input("notas: ").split(" ")
for i in range(len(notas)) :
    suma += float(notas[i])
promedio = round(suma/len(notas), 1)
print (promedio)
