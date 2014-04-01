# -*- coding: utf8 -*-
#
# @file clientes.py
#
# Módulo de clientes
#

clientes = []

class Cliente :
	# atributos del cliente
	rut = ""
	razonsocial = ""
	direccion = ""
	ciudad = ""
	telefono = ""
	# constructor
	def __init__ (self, rut, razonsocial = False, direccion = False, ciudad = False, telefono = False) :
		# si run es un arreglo entonces se pasaron todos los datos como un solo parámetro
		if type(rut)==list :
			self.rut = rut[0]
			self.razonsocial = rut[1]
			self.direccion = rut[2]
			self.ciudad = rut[3]
			self.telefono = rut[4]
		# si rut no es arreglo entonces se pasó cada uno de los parámetros
		else :
			self.rut = rut
			self.razonsocial = razonsocial
			self.direccion = direccion
			self.ciudad = ciudad
			self.telefono = telefono

def cargar (archivo) :
	fd = open(archivo)
	for linea in fd :
		if linea == "\n":
			continue
		# opción 1: recibir cada elementos del arreglo por separado y pasarlos por separado al constructor
		rut, razonsocial, direccion, ciudad, telefono = linea.strip().split(';')
		cliente = Cliente(rut, razonsocial, direccion, ciudad, telefono)
		clientes.append(cliente)
		# opción 2: recibir los elementos en un único arreglo y pasarlo todo junto (como un solo arreglo) al constructor
		datos = linea.strip().split(';')
		cliente = Cliente(datos)
		clientes.append(cliente)
	fd.close()

def guardar (archivo) :
	return False

def listar () :
	# ancho para las columnas
	columnasAncho = 25
	# imprimir nombres de las columnas
	columnas = ["RUT", "Razón social", "Dirección", "Ciudad", "Teléfono"]
	for columna in columnas :
		print (columna, end="")
		print (" "*(columnasAncho-len(columna)), end="")
	print ("")
	# línea de separación
	print("-"*len(columnas)*columnasAncho)
	# imprimir clientes
	for cliente in clientes :
		print (cliente.rut, end="")
		print (" "*(columnasAncho-len(cliente.rut)), end="")
		print (cliente.razonsocial, end="")
		print (" "*(columnasAncho-len(cliente.razonsocial)), end="")
		print (cliente.direccion, end="")
		print (" "*(columnasAncho-len(cliente.direccion)), end="")
		print (cliente.ciudad, end="")
		print (" "*(columnasAncho-len(cliente.ciudad)), end="")
		print (cliente.telefono, end="")
		print (" "*(columnasAncho-len(cliente.telefono)), end="")
		print ("")

def agregar () :
	print("Agregando cliente")

def modificar () :
	print("Modificando cliente")

def eliminar () :
	print("Eliminando cliente")
