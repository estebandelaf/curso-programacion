repetidos = 0
ultimo = 0         

while True:                   
    numero = int(input())
    if numero == ultimo: 
        repetidos += 1         
    else:                      
        repetidos = 1
    if numero == 1:            
        print ("Usted pierde") 
        break                  
    elif repetidos == 3:       
        print ("Usted gana")      
        break                     
    ultimo = numero
