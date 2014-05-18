#!/usr/bin/env python
# -*- coding: utf-8 -*-
print "Bola 8:"
while True:
  try:
    respuesta = int(input("¿Ganara Chile el Mundial?: 1 - si / 2 - no:\n"))
    if respuesta in [1,2]:
      break
  except Exception, e:    
    respuesta = 0
  print("Debes responder 1 para si o 2 para no")
if respuesta is 1:
  print("Vamos chile")
else:
  print("Tengamos mas fe")
