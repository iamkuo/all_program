fn = 1
gn = 1
while True:
    try:
        n = int(input())
    except:
        print(fn,gn)
        break
    for i in range(1,n+1):
        if i == 1:
            gn = 1
            fn = 1
        else:
            fn += i
            gn = fn+gn
    print(fn,gn)
