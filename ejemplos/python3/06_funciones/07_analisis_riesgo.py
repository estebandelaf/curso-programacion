"""
pedro,27,h,s  -> A
maria,29,m,s  -> N
juan,31,h,s   -> N
felipe,25,h,c -> N
"""

archivo = open("input.txt")
for linea in archivo :
    cols = linea.strip().split(",")
    nombre = cols[0]
    edad = int(cols[1])
    sexo = cols[2]
    estado = cols[3] # s = soltero
    if sexo == "h" and edad <= 30 and estado == "s" :
        print(nombre+" es asegurable")
    else :
        print(nombre+" es riesgoso")
archivo.close()
