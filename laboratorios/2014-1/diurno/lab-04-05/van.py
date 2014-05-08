# Valor actual neto 
  
invinicial = int(input("Inversion inicial: ")) 
desct = int(input("% Tasa de descuento: ")) 
cualmes = 1
denom = 1+(desct/100)
van = -1000
devan = 0
while van < 0: 
    flujomes = int(input("Flujo mes "+str(cualmes)+": "))
    devan = devan + (flujomes/(denom**cualmes))
    cualmes += 1
    van = (invinicial*-1)+ devan
    print(round(van))
