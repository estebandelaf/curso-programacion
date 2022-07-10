def get_index(arreglo, buscado) :
	index = -1
	for i in range(len(arreglo)) :
		if arreglo[i] == buscado :
			index = i
			break
	return index

def get_notas(archivo, nota) :
	fd = open(archivo)
	index = 0
	n_linea = 1
	notas = []
	for linea in fd :
		datos = linea.strip().split(",")
		if n_linea == 1 :
			index = get_index(datos, nota)
		else :
			notas.append(float(datos[index]))
		n_linea += 1
	fd.close()
	return notas

def promedio(archivo, nota) :
	notas = get_notas(archivo, nota)
	suma = 0
	for nota in notas :
		suma += nota
	return round(suma/len(notas),1)

print(promedio("notas.txt", "n1"))
print(promedio("notas.txt", "n2"))
print(promedio("notas.txt", "n3"))

"""
# bonus: construir matríz con datos del archivo CSV
def get_datos(archivo) :
	fd = open(archivo)
	datos = []
	for linea in fd :
		datos.append(linea.strip().split(","))
	fd.close()
	return datos

datos = get_datos("notas.txt")
print(datos[3][0])
"""
