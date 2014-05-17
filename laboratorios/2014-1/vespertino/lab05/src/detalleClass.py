class detalle:
    id = 0
    nombre = ""
    cantidad = 0
    
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

    def setCantidad(self,cantidad):
        if cantidad > 0:
            self.cantidad = cantidad
        return self

    def getCantidad(self):
        return self.cantidad

detalle = detalle()
detalle.setId(int(input("ingrese el id\n")))
print(detalle.getId())
