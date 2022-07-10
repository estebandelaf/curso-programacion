# función que lee un archivo csv y lo entrega como arreglo
def csv_read(archivo, separador=",") :
	datos = []
	fd = open(archivo)
	for linea in fd :
		datos.append(linea.strip().split(separador))
	fd.close()
	return datos

# función que guarda un arreglo en un archivo
def arreglo_guardar(archivo, alumnos) :
	fd = open(archivo, "w")
	for nombre in alumnos :
		fd.write(nombre+"\n")
	fd.close()

# obtener dato del archivo csv
alumnos = csv_read("notas.txt")

# procesar cada alumno
aprobados = []
examen = []
reprobados = []
for alumno in alumnos:
	nombre = alumno[0]
	n1 = float(alumno[1])
	n2 = float(alumno[2])
	n3 = float(alumno[3])
	promedio = round((n1+n2+n3)/3, 1)
	if promedio >= 5 :
		aprobados.append(nombre)
	elif promedio >= 4 :
		examen.append(nombre)
	else :
		reprobados.append(nombre)

# guardar los arreglos en los archivos
arreglo_guardar("aprobados.txt", aprobados)
arreglo_guardar("examen.txt", examen)
arreglo_guardar("reprobados.txt", reprobados)
