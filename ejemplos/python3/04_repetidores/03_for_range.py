#         0123456789
string = "Hola Mundo"
print(string[5])
print(string[0]+string[5])

# mostrar string hacia abajo con while
ultimaCasilla = len(string) - 1
i = 0
while i <= ultimaCasilla :
    print(string[i])
    i = i + 1

# mostrar string hacia abajo con for
for letra in string :
    print(letra) # letra es la variable, puede ser l

for i in range(len(string)) :
    print(string[i])

"""
range(a): genera desde 0 hasta a-1
range(a,b): genera desde a hasta b-1
range(a,b,c): genera desde a hasta b-1 con incremento c
"""
