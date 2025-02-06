try:
    while 87:
        r,c = [int(i) for i in input().split()]
        dat = []
        for i in range(r):
            dat.append([int(i) for i in input().split()])
        for i in range(c):
            for j in range(r):
                print(dat[j][i],end = " ")
            print()
except EOFError:
    pass
