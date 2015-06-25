def posicion(x0, v, t, a) :
    return x0 + v*t + (1/2)*a*t**2

print(posicion(1, 2.3, 10, 9.8))
print(posicion(2, 2, 5, 9.8))
