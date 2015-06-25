"""
Programa que calcula la velocidad de un objeto e indica ...
acá sigue el comentario
"""

d = float(input("distancia [km] = "))
t = float(input("tiempo [h] = "))
v = d / t # cálculo de velocidad

velocidadPermitida = 60 # km/h

if v > velocidadPermitida :
    print ("Velocidad excedida")
    print ("Bajar velocidad")
