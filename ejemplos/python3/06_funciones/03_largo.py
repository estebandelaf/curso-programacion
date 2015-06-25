def largo (string) :
    largo = 0
    for letra in string :
        largo += 1
    return largo

s1 = "Hola mundo!"
print(len(s1))
print(largo(s1))

s2 = "Esta es otra frase"
print(len(s2))
print(largo(s2))
