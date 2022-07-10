#a = [1, 2, 3, 4, 5]

a = [[1, 2, 3], [1, 1, 1], [2, 2, 2]]
b = [[1, 2, 3], [1, 1, 1], [2, 2, 2]]

c = []
for i in range ( len(a) ):
    c.append( [0] * len(a ) )
print(c)
for i in range( len( a ) ):
    for j in range( len( b ) ):
        c[i][j] = a[i][j] + b[i][j]

for i in range( len( a ) ):
    for j in range( len( b ) ):
        print(c[i][j])
print(c)
