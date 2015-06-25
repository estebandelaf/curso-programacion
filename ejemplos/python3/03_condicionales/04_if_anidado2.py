edad = int(input("Ingrese edad: "))

"""
este es un ejemplo de if anidado, la opción "else" no es
obligatoria
"""
if edad >= 0 and edad < 14 :
    print ("niño")
elif edad >= 14 and edad < 18 :
    print ("adolescente")
elif edad >= 18 :
    print ("adulto")
else :
    print ("Edad no válida")

"""
este if no tiene que ver con el anterior, a pesar
que usa la misma variable
"""
if edad >= 18 :
    print ("Puede votar")
else :
    print ("No puede votar")
