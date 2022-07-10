def menu():
	print("Menú principal")
	print("1) Opción 1")
	print("2) Opción 2")
	print("0) Salir")
	return int(input("Ingresar una opción: "))

def menu1():
	print("=======================")
	print("Sub menú principal 1   ")
	print("=======================")
	print("1) Opción 1")
	print("2) Opción 2")
	print("0) Salir")
	opcion = int(input("Ingresar una opción: "))
	if opcion == 1:
		menu1_opcion1()
	elif opcion == 2:
		menu1_opcion2()
	else:
		print("Opción inválida!")
	return opcion

def menu1_opcion1():
	print("Ejecutando opción 1 de submenu principal 1")

def menu1_opcion2():
	print("Ejecutando opcion 2 de submenu principal 1")

def menu2():
	print("=======================")
	print("Sub menú principal 2   ")
	print("=======================")
	print("1) Opción 1")
	print("2) Opción 2")
	print("0) Salir")
	opcion = int(input("Ingresar una opción: "))
	if opcion == 1:
		menu2_opcion1()
	elif opcion == 2:
		menu2_opcion2()
	else:
		print("Opción inválida!")
	return opcion

def menu2_opcion1():
	print("Ejecutando opción 1 de submenu principal 2")

def menu2_opcion2():
	print("Ejecutando opcion 2 de submenu principal 2")

salir = False
while not salir:
	opcionMenu = menu()
	if opcionMenu == 1:
		salirSubMenu = False
		while not salirSubMenu :
			opcionSub = menu1()
			if not opcionSub :
				salirSubMenu = True
		print("Saliendo del sub menú principal 1")
	elif opcionMenu == 2 :
		salirSubMenu = False
		while not salirSubMenu :
			opcionSub = menu2()
			if not opcionSub :
				salirSubMenu = True
		print("Saliendo del sub menú principal 2")
	elif opcionMenu == 0:
		salir = True
	else:
		print("Opción incorrecta")

print("Saliendo del menú principal")
