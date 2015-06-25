def print2D(arreglo) :
    for i in range(len(arreglo)) :
        for j in range(len(arreglo[i])) :
            print(arreglo[i][j], end=" ")
        print()

print2D([[1,2],[3,4]])
"""
1 2
3 4
"""
print2D([[1,2,3,4]])
print2D([[1]])
print2D([[1],[2],[3],[4]])
