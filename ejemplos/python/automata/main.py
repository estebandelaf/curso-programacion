#!/usr/bin/python
#-*- coding: utf-8 -*-

# hacer import del autómata
from Automata import AFD

# reconocer cantidad impar de 0s
impar_de_ceros = AFD({ 0: { '0': 1, '1': 0 }, 1: { '0': 0, '1': 1 } }, [1], 0)
print(impar_de_ceros.test(""))             # False
print(impar_de_ceros.test("0"))            # True
print(impar_de_ceros.test("00"))           # False
print(impar_de_ceros.test("1"))            # False
print(impar_de_ceros.test("10"))           # True
print(impar_de_ceros.test("01010"))        # True
print(impar_de_ceros.test("0101010101"))   # True
print(impar_de_ceros.test("1010101"))      # True

# reconocer cantidad par de 0s
par_de_ceros = AFD({ 0: { '0': 1, '1': 0 }, 1: { '0': 0, '1': 1 } }, [0])
print(par_de_ceros.test(""))             # True
print(par_de_ceros.test("0"))            # False
print(par_de_ceros.test("00"))           # True
print(par_de_ceros.test("1"))            # True
print(par_de_ceros.test("10"))           # False
print(par_de_ceros.test("01010"))        # False
print(par_de_ceros.test("0101010101"))   # False
print(par_de_ceros.test("1010101"))      # False
