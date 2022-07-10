"""
Definición de factorial por inducción (para números positivos):
- Caso base: 1+ = 1
- Caso general: n+= n + (n-1)+
"""

def sumar(N) :
	suma = 0
	for i in range(1,N+1) :
		suma += i
	return suma

def sumar2(N) :
	if N == 1:
		return 1
	else :
		return N + sumar2(N-1)

print(sumar(5)) # 15
print(sumar2(5)) # 15
