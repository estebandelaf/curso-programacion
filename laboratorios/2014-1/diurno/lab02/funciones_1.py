def maximo (n1, n2) :
	if n1 > n2 :
		mayor = n1
	else :
		mayor = n2
	return mayor

x = input("numero:")
y = input("otronumero:")

print (maximo(x, y))
