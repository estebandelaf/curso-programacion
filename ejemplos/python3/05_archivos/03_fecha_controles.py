"""
Bajar calendario CSV de la web del curso
"""
archivo = open ("input.txt")
for linea in archivo :
    aux = linea.strip().replace("\"", "").split(",")
    if aux[1] == "Control 1" or aux[1] == "Control 2" :
        print(aux[1]+": "+aux[0])
archivo.close()
