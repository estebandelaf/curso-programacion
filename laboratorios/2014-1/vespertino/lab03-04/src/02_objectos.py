#!/usr/bin/env python
# -*- coding: utf-8 -*-

class Persona:

    def __init__(self):
        self.id = 0
        self.nombre = ""
        self.email = ""

    def setId(self,id):
        if id >= 1:
            self.id = id
        return self

    def getId(self):
        return self.id

    def setNombre(self,nombre):
        self.nombre = nombre
        return self

    def getNombre(self):
        return self.nombre

    def setEmail(self,email):
        self.email = email
        return self

    def getEmail(self):
        return self.email

class Alumno(Persona):

    def __init__(self):
        self.nota = 0

    def setNota(self,nota):
        if id >= 0:
            self.nota = nota
        return self

    def getNota(self):
        return self.nota

class Profesor(Persona):

    def __init__(self):
        self.evaluacionAcademica = 0

    def setEvaluacionAcademica(self,evaluacionAcademica):
        if id >= 0:
            self.evaluacionAcademica = evaluacionAcademica
        return self

    def getEvaluacionAcademica(self):
        return self.evaluacionAcademica

class Clase:

    def __init__(self):
        self.nombre = ""
        self.curso = ""
        self.alumnos = []
        self.profesores = []

    def setNombre(self,nombre):
        self.nombre = nombre
        return self

    def getNombre(self):
        return self.nombre

    def setCurso(self,curso):
        self.curso = curso
        return self

    def getCurso(self):
        return self.curso

    def addAlumno(self,alumno):
        self.alumnos.append(alumno)
        return self

    def getAlumnos(self):
        return self.alumnos


detalle.setId(int(input("ingrese el id\n")))
print(detalle.getId())
