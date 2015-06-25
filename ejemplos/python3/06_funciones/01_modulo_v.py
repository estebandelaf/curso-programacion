def modulo_v(ax, ay, az) :
    return (ax**2+ay**2+az**2)**(1/2)

a = int(input("ax"))
b = int(input("ay"))
c = int(input("az"))
print(modulo_v(a,b,c))

print(modulo_v(1,2,4))
print(modulo_v(1,5,3))
print(modulo_v(-1,2,3))

valor = modulo_v(1,2,3)
print(valor)

