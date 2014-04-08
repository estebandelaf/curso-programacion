import math
run = 1
print ("Bienvenido, seleccione una opcion\n 1) Suma \n 2) Resta \n 3) Multiplicacion \n 4) Division \n 5) Potencia \n 6) Raiz Cuadrada \n 7) Calculo de ecuaciones cuadraticas \n 8) Saber si pase el ramo \n 9) Salir")
while run == 1:
	try:
		opcion = int(input("Ingrese numero de opcion: "))
		if opcion == 1:
			n1 = int(input("Ingrese numero a sumar: "))
			n2 = int(input("Ingrese segundo numero a sumar: "))
			print ("El resultado es",n1+n2)
		elif opcion == 2:
			n1 = int(input("Ingrese numero al cual restar: "))
			n2 = int(input("Ingrese segundo numero a restar: "))
			print ("El resultado es",n1-n2)
		elif opcion == 3:
			n1 = int(input("Ingrese numero a multiplicar: "))
			n2 = int(input("Ingrese segundo a multiplicar: "))
			print ("El resultado es",n1*n2)
		elif opcion == 4:
			n1 = int(input("Ingrese numero a dividir: "))
			n2 = int(input("Ingrese segundo a dividir: "))
			print ("El resultado es",n1/n2)
		elif opcion == 5:
			n1 = int(input("Ingrese numero base: "))
			n2 = int(input("Ingrese numero exponente: "))
			print ("El resultado es",n1**n2)
		elif opcion == 6:
			n1 = int(input("Ingrese numero a extraer raiz: "))
			print ("El resultado es",math.sqrt(n1))
		elif opcion == 7:
			a = float(input("Ingrese a: "))
			b = float(input("Ingrese b: "))
			c = float(input("Ingrese c: "))
			discriminante = b ** 2 - 4 * a * c
			if discriminante < 0:
				print ("La ecuacion no tiene soluciones reales")
			elif discriminante == 0:
				x = -b / (2 * a)
				print ("La solucion unica es x ="), x
			else:
				x1 = (-b - (discriminante ** 0.5)) / (2 * a)
				x2 = (-b + (discriminante ** 0.5)) / (2 * a)
				print ("Las dos soluciones reales son:")
				print ("x1 ="), x1
				print ("x2 ="), x2
		elif opcion == 8:
			n1 = float(input("Solemne 1: "))
			n2 = float(input("Solemne 2: "))
			n3 = float(input("Ayudantias: "))
			nf = n1*0.3+n2*0.3+n3*0.4
			if nf >= 4:
				print (nf,"Pasa el ramo :)")
			else:
				print (nf,"No pasa el ramo")
		elif opcion == 9:
			print ("Saliendo...")
			run = 0
		else:
			print ("Opcion invalida")
	except Exception:
		print ("Error, ingrese caracteres validos")
