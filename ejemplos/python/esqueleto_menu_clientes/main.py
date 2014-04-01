#!/usr/bin/python
# -*- coding: utf8 -*-
#
# @file main.py
#
# Programa principal de la aplicación
#
# @author Esteban De La Fuente Rubio, DeLaF (esteban[at]delaf.cl)
# @version 2013-05-04
#

# importar módulos
import modules.menu as menu
import modules.clientes as clientes

# configuración
CLIENTES_ARCHIVO = "data/clientes.csv"

# cargar datos de clientes desde archivo CSV
clientes.cargar(CLIENTES_ARCHIVO)

# ejecutar menú principal
menu.principal()

# guardar datos de clientes en el archivo CSV
clientes.guardar(CLIENTES_ARCHIVO)
