# función que carga una matriz de NxM desde un archivo
def matriz_cargar(archivo) :
	matriz = []
	fd = open(archivo)
	for linea in fd :
		valores = linea.strip().split(" ")
		#fila = []
		#for valor in valores :
		#	fila.append(int(valor))
		#matriz.append(fila)
		for i in range (len(valores)) :
			valores[i] = int(valores[i])
		matriz.append(valores)
	return matriz

# función que suma dos matrices de NxM
def matriz_sumar(m_1, m_2) :
	suma = []
	filas = len(m1)
	columnas = len(m1[0])
	for i in range(filas) :
		fila = []
		for j in range(columnas) :
			s = m_1[i][j] + m_2[i][j]
			fila.append(s)
		suma.append(fila)
	return suma

# función que guarda una matriz de NxM en un archivo
def matriz_guardar(archivo, matriz) :
	fd = open(archivo, "w")
	filas = len(matriz)
	columnas = len(matriz[0])
	for i in range(filas) :
		for j in range(columnas) :
			fd.write(str(matriz[i][j])+" ")
		fd.write("\n")
	fd.close()

# caso de prueba
m1 = matriz_cargar("m1.txt")
m2 = matriz_cargar("m2.txt")
#if not matriz_verificar(m1, 2, 3) :
#	print("error")
m3 = matriz_sumar(m1, m2)
matriz_guardar("m3.txt", m3)

# valores de matrices
print(m1)
print(m2)
print(m3)
