#!/usr/bin/env python
# -*- coding: utf-8 -*-

numero = int(input("ingrese un numero:\n"))

def fino(n):
    if( n <= 0):
       print ("condicion inicial 0")
       return 0
    elif (n == 1):
       print ("condicion inicial 1")
       return 1
    else:
       print ("condicion recursividad con n= %d")%(n)
       fun1 = fino(n-1)
       fun2 = fino(n-2)
       print ("valores de func1 = %d y func2 = %d")%(fun1,fun2)
       a = fun1 + fun2
       print ("Valor acumulado es %d")%(a)
       return a

print fino(numero)
