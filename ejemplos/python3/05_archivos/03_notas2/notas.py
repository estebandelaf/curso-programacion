def get_file_contents(archivo) :
	fd = open(archivo)
	texto=""
	for linea in fd :
		texto += linea
	fd.close()
	return texto

def promedio(arreglo) :
	suma = 0
	for i in range(1, len(arreglo)) :
		notas = arreglo[i].split(",")
		suma_curso = 0
		for j in range(1, len(notas)) :
			suma_curso += float(notas[j])
		promedio_curso = round(suma_curso / (len(notas) - 1), 1)
		suma += promedio_curso
	return round(suma / (len(arreglo) - 1), 1)

contenido = get_file_contents("notas.txt")
alumnos = contenido.strip().split("*")

for alumno in alumnos :
	datos = alumno.strip().split("\n")
	nombre, apellido = datos[0].split(",")
	# aux = datos[0].split(",")
	# nombre = aux[0]
	# apellido = aux[1]
	print(nombre, apellido, promedio(datos))
