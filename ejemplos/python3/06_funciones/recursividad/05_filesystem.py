import sys
import os

def showFiles(dir) :
	# obtener achivos y carpetas
	files = os.scandir(dir)
	# iterar cada archivo y carpeta
	for f in files :
		# si es directorio se entra al
		# directorio recursivamente
		if f.is_dir() :
			showFiles(f.path)
			#showFiles(dir+"/"+f.name)
		# si es archivo se imprime su ruta
		else :
			print(f.path)
			#print(dir+"/"+f.name)

showFiles(sys.argv[1])
