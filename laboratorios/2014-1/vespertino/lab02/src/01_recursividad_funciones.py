#!/usr/bin/env python
# -*- coding: utf-8 -*-

#Primero se debe definir la función que se utilizara
def factorial(n):
        #Definición de la condición o condiciones de termino
	if (n == 1):
	   return 1
	#Definición de la condición o condiciones de recursividad
	else:
		a = factorial( n - 1)
		return a*n

# Petición de las entradas (Clase anterior)
numero = input("Ingrese un numero \n")
# Llamado de la función y entrega de resultados
print(factorial(numero))
