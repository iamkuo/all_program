a = 1
b = 1
c = 1
d = int(input("enter a number:"))
if d == 1:
    print(a)
elif d == 2:
    print(a)
    print(b)
elif d == 3:
    print(a)
    print(b)
    b = a + b
    print(b)
else:
    print(a)
    print(b)
    b = a + b
    print(b)
    for i in range(d - 3):
        c = b
        b = a + b
        a = c
        print(b)
    
    
