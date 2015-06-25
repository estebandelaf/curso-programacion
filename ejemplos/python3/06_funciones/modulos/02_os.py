import sys
import os

if len(sys.argv) != 2 :
	print("[error] modo de uso: "+sys.argv[0]+" DIR")
	sys.exit(1)

if not os.path.isdir(sys.argv[1]) :
	print("[error]: "+sys.argv[1]+" no es un directorio")
	sys.exit(1)

directorio = sys.argv[1] # parámetro pasado como argumento al programa
if directorio[len(directorio)-1] != "/" :
	directorio += "/"
archivos = os.listdir(directorio)
for archivo in archivos :
	archivo_ruta = directorio+archivo
	print(archivo_ruta, end=": ")
	if os.path.isdir(archivo_ruta) :
		print("es directorio")
	elif os.path.isfile(archivo_ruta) :
		print("es archivo regular")
	else :
		print("no es directorio ni archivo regular")

"""
Contenido del directorio /home/delaf/tmp/progra:
$ ls -lh /home/delaf/tmp/progra
total 4,0K
drwxr-xr-x 5 delaf users 4,0K sep  4 13:11 d1
-rw-r--r-- 1 delaf users    0 sep  4 13:11 f1

Ejecución y salida del programa:
$ python3 02_os.py /home/delaf/tmp/progra
/home/delaf/tmp/progra/d1: es directorio
/home/delaf/tmp/progra/f1: es archivo regular
"""
