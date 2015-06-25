#       Todo es un arreglo 3D
#      arreglo 2D     arreglo 2D
#        1D   1D        1D    1D
A = [ [[1,2],[3,4]], [[5,6],[7,8]] ]

for i in range(len(A)) :
    for j in range (len(A[i])) :
        for k in range (len(A[i][j])) :
            print(A[i][j][k])

print("-"*20)

def print2D(arreglo) :
    for i in range(len(arreglo)) :
        for j in range(len(arreglo[i])) :
            print(arreglo[i][j], end=" ")
        print()

for i in range(len(A)) :
    print2D(A[i])
    print()
