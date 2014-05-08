n=int(input("n: "))
productos=int(input("Cantidad productos: "))
p_desc = 20                 
descuento_total = 0         
descuento_parcial = 0       
n_productos = 0            
precio_total = 0           

for i in range (1, productos + 1):

    precio = int(input("Precio producto " + str(i) + ": "))        
    n_productos += 1
    descuento_parcial = descuento_parcial + precio * (p_desc / 100.0)  
    precio_total = precio_total + precio                               

    if n_productos == n:                                        

        descuento_total = descuento_total + descuento_parcial  
        p_desc = p_desc / 2                                    
        descuento_parcial = 0                                   
        n_productos = 0

print ("Total:", precio_total)
print ("Descuento:", int(descuento_total))
print ("A pagar:", int(precio_total - descuento_total))
