#!/usr/bin/env python
# -*- coding: utf-8 -*-
print "Bola 8:"
while True:
  try:
    respuesta = int(input("¿Ganara Chile el Mundial?:\n1 - si / 2 - no / 3 - no se :\nRespuesta"))
    if respuesta in [1,2,3]:
      break
  except Exception, e:    
    respuesta = 0
  print("Debes responder 1 para si o 2 para no o 3 para no se")
if respuesta == 1:
  print("Vamos chile")
elif respuesta == 2:
  print("Tengamos mas fe")
else:
  print("Debemos definirnos")
exit()
# Solo para aclaración. La equivalencia es  
if respuesta == 1:
  print("Vamos chile")
else:
  if respuesta == 2:
    print("Tengamos mas fe")
  else:
    print("Debemos definirnos")
