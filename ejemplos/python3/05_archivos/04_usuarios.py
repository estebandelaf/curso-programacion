fd = open("/etc/passwd")
for linea in fd :
    d = linea.strip().split(":")
    print(d[0], d[5])
fd.close()

