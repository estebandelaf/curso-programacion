# -*- coding: utf8 -*-
#
# @file funciones.py
#
# Módulo de funciones generales de aplicaciones
#

# importar módulos
import os

# función que limpia la pantalla
def screen_clear () :
	if os.name == "posix" :
		os.system("clear")
	elif os.name == "nt" :
		os.system("cls")

# función que pide presionar enter (mientras espera)
def screen_pause () :
	input("\nPresione ENTER para continuar... ")


# función que lee un entero desde la entrada estándar
def getInt (msg = "") :
	while True :
		try :
			return int(input(msg))
		except :
			print ("\n[error] el valor ingresado debe ser un número")
