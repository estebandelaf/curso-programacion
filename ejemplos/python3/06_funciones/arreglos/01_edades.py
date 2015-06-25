"""
# Datos generados usando:
import random
for i in range (1,1001) :
    print ("Persona "+str(i)+","+str(random.randrange(18,45)))
"""

def personas_cargar(archivo) :
    personas = []
    fd = open(archivo)
    for linea in fd :
        aux = linea.strip().split(",")
        personas.append([aux[0], int(aux[1])])
    fd.close()
    return personas

def personas_edad(personas, edad) :
    listado = []
    for persona in personas :
        if persona[1] == edad :
            listado.append(persona[0])
    return listado

def edad_minima(personas) :
    e_minima = 200
    for persona in personas :
        if persona[1] < e_minima :
            e_minima = persona[1]
    return e_minima

def edad_maxima(personas) :
    e_maxima = -1
    for persona in personas :
        if persona[1] > e_maxima :
            e_maxima = persona[1]
    return e_maxima

def edades_porcentaje(personas) :
    personas_total = len(personas)
    edades_totales = []
    edades_porcentajes = []
    for i in range(0, 131) :
        edades_totales.append(0)
    for persona in personas :
        edades_totales[persona[1]] += 1
    for edad in range (0, len(edades_totales)) :
        if edades_totales[edad] == 0 :
            continue
        p = round((edades_totales[edad]/personas_total)*100)
        edades_porcentajes.append([edad, p])
    return edades_porcentajes

# cargados personas
personas = personas_cargar("input.txt")

# mostramos personas que tienen 20 años
listado = personas_edad(personas, 20)
for p in listado :
    print (p)

# edad mínima y máxima
print(edad_minima(personas), edad_maxima(personas))

# mostramos porcentajes de cada edad
for edad in edades_porcentaje(personas) :
    print (str(edad[0])+": "+str(edad[1])+"%")
