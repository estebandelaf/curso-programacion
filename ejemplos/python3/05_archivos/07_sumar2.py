fd = open("input.txt")
for linea in fd :
    n1, n2 = linea.strip().split(" ")
    #lista = linea.strip().split(" ")
    #n1 = lista[0]
    #n2 = lista[1]
    print(int(n1)+int(n2))
fd.close()

