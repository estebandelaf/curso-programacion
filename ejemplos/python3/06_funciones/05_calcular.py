"""
Ejemplo de archivo input.txt:
1,+,1
1,-,1
-2,+,1
-2,+,1.5
"""
def calcular(a) :
    archivo = open(a)
    for linea in archivo :
        aux = linea.strip().split(",")
        n1 = float(aux[0])
        op = aux[1]
        n2 = float(aux[2])
        if op == "+" :
            r = n1 + n2
        else :
            r = n1 - n2
        print(n1, op, n2, r)
    archivo.close()
calcular("input.txt")
#calcular("input2.txt")
