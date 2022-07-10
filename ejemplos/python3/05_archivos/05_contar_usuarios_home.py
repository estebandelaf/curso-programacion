def contar(dir = "/") :
    usuarios = 0
    fd = open("/etc/passwd")
    for linea in fd :
        d = linea.strip().split(":")
        if d[5] == dir :
            usuarios += 1
    fd.close()
    return usuarios

print(contar())
print(contar("/"))
print(contar("/home/delaf")) # 1

