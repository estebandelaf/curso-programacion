#!/usr/bin/python
#-*- coding: utf-8 -*-
#
# Clase para ejecutar un AFD (autómata finito determinístico)
# @author Esteban De La Fuente Rubio, DeLaF (esteban[at]delaf.cl)
#

class AFD :

  # diccionario con las transiciones
  # transiciones = {
  #   'estado actual': { 'simbolo que se ve': 'estado al que se pasa' }
  # }
  # el símbolo siembre debe ser un string, aunque sea un número, o sea
  # si el símbolo es 0, se debe colocar como '0' o "0"
  transiciones = {}

  # único estado inicial
  estadoInicial = 0

  # conjunto de estados finales
  estadosFinales = []

  # constructor
  def __init__ (self, transiciones, estadosFinales, estadoInicial = 0) :
    self.transiciones = transiciones
    self.estadoInicial = estadoInicial
    self.estadosFinales = estadosFinales

  # función que evalua el string a partir del diccionario de transiciones
  def test (self, w) :
    estado = self.estadoInicial
    for i in range(len(w)) :
      estado = self.transiciones[estado][w[i]]
    return estado in self.estadosFinales
