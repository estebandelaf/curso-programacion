def bin_impar_unos(string) :
    estado = 0
    for digito in string :
        if estado == 0 and digito == "1" :
            estado = 1
        elif estado == 1 and digito == "1" :
            estado = 0
    if estado == 1 :
        return True
    else :
        return False

print(bin_impar_unos("0")) # False
print(bin_impar_unos("1")) # True
print(bin_impar_unos("11")) # False
print(bin_impar_unos("01")) # True

if bin_impar_unos("111") :
    print("El string 111 tiene impar de 1's")
