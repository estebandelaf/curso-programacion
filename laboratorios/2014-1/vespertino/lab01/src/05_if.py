#!/usr/bin/env python
# -*- coding: utf-8 -*-
edad = int(input("¿Que edad tienes?"))
if edad < 0:
    print("Ingresa una edad valida")
elif edad < 18:
    print("Eres un menor de edad")
elif edad > 65:
    print("Eres un adulto mayor")
else:
    print("Eres un adulto promedio")
