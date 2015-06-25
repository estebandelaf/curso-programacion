# arreglo de una dimensión
A1 = [1,2,5,3]
print(A1[1])
print("-"*20)
for i in range(len(A1)) :
    print(A1[i]) # diferente a print(i)
print("-"*20)

# sumar dos arreglos de una dimension
A1 = [1,2,3,4]
A2 = [4,3,2,1]
if len(A1) == len(A2) :
    for i in range(len(A1)) :
        print(A1[i]+A2[i])
print("-"*20)

# arreglo de 2 dimensiones
A1 = [ [1,2], [3,4] ]
print(A1[0][1])
print("-"*20)
for i in range(len(A1)) :
    for j in range(len(A1[i])) :
        print(A1[i][j])
print("-"*20)

# sumar arreglos bidimensionales
A1 = [ [1,2], [3,4] ]
A2 = [ [5,6], [7,8] ]
for i in range(len(A1)) :
    for j in range(len(A1[i])) :
        print(A1[i][j]+A2[i][j])
