edad = int(input("Ingrese edad: "))
if edad >= 0 and edad < 14 :
    print ("niño")
else :
    if edad >= 14 and edad < 18 :
        print ("adolescente")
    else :
        if edad >= 18 :
            print ("adulto")
        else :
            print ("edad inválida")
