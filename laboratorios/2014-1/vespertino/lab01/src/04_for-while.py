#!/usr/bin/env python
# -*- coding: utf-8 -*-
print "Asistencia"
list= [
        'OMAR ABURTO IBAÑEZ',
        'RODRIGO GODOY VARGAS',
        'MARGARITA ROGAT GODOY',
        'CRISTOBAL TRINCADO MORALES',
    ]

#print list

for item in list:
  while True:
    try:
      respuesta = int(input("Vino %s?: 1 - si / 2 - no:\n"%item))
      if respuesta in [1,2]:
        break
    except Exception, e:    
      respuesta = 0
      print "Debes responder 1 para si o 2 para no"
  if respuesta == 1:
    print "Bienvenid@ %s: " % item
