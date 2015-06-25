"""
Ejemplo de input.txt:
hola mundo
chao mundo feo
estamos en clases de
programacion
"""
archivo = open ("input.txt")
for linea in archivo :
    print (linea, end="")
archivo.close()
