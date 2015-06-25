edad = int(input("Ingrese edad: "))

# malo, solución: anidar
if edad < 14 :
    print ("niño")
if edad < 18 :
   print ("adolescente")
if edad >= 18 :
    print ("adulto")

# malo, solución: rangos
if edad >= 18 :
    print ("adulto")
elif edad < 18 :
   print ("adolescente") 
elif edad < 14 :
   print ("niño")
