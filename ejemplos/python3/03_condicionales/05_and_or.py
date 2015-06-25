a = int(input("a: "))
b = int(input("b: "))

# esto es ejemplo de AND
if a == 3 :
    if b == 5 :
        print ("a es 3 y b es 5")
if a == 3 and b == 5 :
    print ("a es 3 y b es 5")

# esto es ejemplo de OR
if a == 3 :
    print ("a es 3")
if a == 5 :
    print ("a es 5")
if a == 3 or a == 5 :
    print ("a es 3 o a es 5")
