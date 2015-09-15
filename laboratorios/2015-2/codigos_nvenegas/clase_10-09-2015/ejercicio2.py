a = [[1, 2, 3], [1, 1, 1], [2, 2, 2]]
arrSuma = []
for i in range( len( a ) ):
    suma = 0
    for j in range( len( a )):
        suma = suma + a[i][j]
    arrSuma.append( suma )

for i in range( len( a ) ):
    for j in range( i + 1, len( a )):
        #print("i = ", i , " j = " , j) 
        if ( arrSuma[i] == arrSuma[j] ):            
            print("La matriz es prima")
print(arrSuma)
