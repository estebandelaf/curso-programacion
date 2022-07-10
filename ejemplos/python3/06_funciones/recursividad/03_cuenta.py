def cuenta(n):
    if n != 1 :
        cuenta(n-1)
    print(n)

cuenta(10)

