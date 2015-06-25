archivo = open("input.txt")
for linea in archivo :
    cols = linea.strip().split(",")
    nombre = cols[0]
    edad = int(cols[1])
    sexo = cols[2]
    estado = cols[3]
    if sexo == "h" and edad <= 30 and estado == "s" :
        print(nombre+" es asegurable")
        print(linea.strip()+",asegurable")
    else :
        print(nombre+" es riesgoso")
        print(linea.strip()+",riesgoso")
archivo.close()
