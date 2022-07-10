# enteros son inmutables
def f1(numero) :
	numero = 1
a = 2
f1(a)
print(a) # 2

# arreglos son mutables
def f2(arreglo) :
	arreglo[0] = 1
b = [2]
f2(b)
print(b[0])
