suma = 0
for i in range(5) :
    nota = float(input("nota: "))
    #print(nota)
    suma += nota # suma = suma + nota
promedio = round(suma/5, 1)
print (promedio)
