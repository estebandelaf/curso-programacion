"""
Programa que indica el valor que se debe pagar en el metro de acuerdo a la hora
en la que se está viajando (horarios y valores no representan la realidad)
"""

# solicitar hora al usuario y entregar como un número decimal
hora = input("Ingrese hora (HH:MM, HH.MM o HHMM): ")
hora = hora.replace(":", "").replace(".", "")
if len(hora) == 3 :
    hora = "0"+hora
h = int(hora[0:2])
m = int(hora[2:4])
if h < 0 or h > 23 or m < 0 or m > 59:
    print ("Formato de hora inválido")
    exit(1)
hora = h + m/100

# verificar el horario en el que nos encontramos y definir precio de pasaje
if (hora >= 6.00 and hora < 9.00) or (hora >= 18.01 and hora < 21.00) :
    valor = 650
elif hora >= 9.01 and hora < 18.00 : 
    valor = 610
else :
    valor = 600

# mostrar precio del pasaje
print("Debe cancelar $"+str(valor))
