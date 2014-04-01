t = int(input("hora actual: ")) #Solicitamos las horas al usuario
h = int(input("cantidad de horas: ")) 
  
print ("En "+str(h)+" horas, el reloja marcara las "+str((t+h)%24)) #La funcion % (modulo) permite calcular el resto, sabiendo asi la hora que sera dentro de una determinada cantidad de horas
