# -*- coding: utf8 -*-
#
# @file menu.py
# 
# Módulo de menús de la aplicación
#

# importar módulos
from modules.funciones import *
import modules.clientes as clientes

# menú
def principal () :
	salir = False
	while not salir :
		# limpiar pantalla
		screen_clear()
		# mostrar opciones del menú
		print("1. Menú de clientes")
		print("0. Salir")
		# solicitar el ingreso de la opción
		opcion = getInt("Ingrese la opción que desea ejecutar: ")
		# según la opción elegida se toma alguna acción
		if opcion == 1 :
			submenu_clientes()
		elif opcion == 0 :
			salir = True
		else :
			option_wrong()
			# solicitar ENTER para pasar a siguiente iteración
			screen_pause()

def submenu_clientes () :
	while True :
		# limpiar pantalla
		screen_clear()
		# mostrar opciones del menú
		print("1. Listar clientes")
		print("2. Agregar un cliente")
		print("3. Modificar un cliente")
		print("4. Eliminar un cliente")
		print("0. Volver al menú principal")
		# solicitar el ingreso de la opción
		opcion = getInt("Ingrese la opción que desea ejecutar: ")
		# limpiar pantalla
		screen_clear()
		# según la opción elegida se toma alguna acción
		if opcion == 1 :
			clientes.listar()
		elif opcion == 2 :
			clientes.agregar()
		elif opcion == 3 :
			clientes.modificar()
		elif opcion == 4 :
			clientes.eliminar()
		elif opcion == 0 :
			break
		else :
			option_wrong()
		# solicitar ENTER para pasar a siguiente iteración
		screen_pause()

def option_wrong () :
	print ("\n[error] la opción ingresada es incorrecta")
