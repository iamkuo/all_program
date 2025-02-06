a = input().split()
r,c,k,m = [int(i) for i in a]
neib = []
mov = []
def checkdir(neib,i,j):
    way = []
    try:
        a = neib[i][j-1]#up
        way.append(1)
        print('dir',i,j,way[len(way)])
    except:c
        pass
    try:
        a = neib[i][j+1]#down
        way.append(2)
        print('dir',i,j,way[len(way)])
    except:
        pass
    try:
        a = neib[i-1][j]#left
        way.append(3)
        print('dir',i,j,way[len(way)])
    except:
        pass
    try:
        a = neib[i+1][j]#right
        way.append(4)
        print('dir',i,j,way[len(way)])
    except:
        pass
    return way
for i in range(r):
    neib.append([])
    tmp = input().split()
    tmp = [int(i) for i in tmp]
    for j in range(c):
        neib[i].append(tmp[j])
print(neib)
for days in range(m):
    mov = []
#create empty mov
    for i in range(len(neib)):
        mov.append([])
        for j in range(len(neib[i])):
            mov[i].append(0)
#check dir
    for i in range(len(neib)):
        for j in range(len(neib[i])):
            #in each slots
            way = checkdir(neib,i,j)
            print(i,j,way)
            for K in range(4):
                try:
                    if way[K] == 1:#up
                        tmp = int(neib[i][j]/k)
                        mov[i][j] -= tmp
                        mov[i][j-1] +=tmp
                except:
                    pass
                try:
                    if way[K] == 2:#down
                        tmp = int(neib[i][j]/k)
                        mov[i][j] -= tmp
                        mov[i][j+1] +=tmp
                except:
                    pass
                try:
                    if way[K] == 3:#left
                        tmp = int(neib[i][j]/k)
                        mov[i][j] -= tmp
                        mov[i-1][j] +=tmp
                except:
                    pass
                try:
                    if way[K] == 4:#right
                        tmp = int(neib[i][j]/k)
                        mov[i][j] -= tmp
                        mov[i+1][j] +=tmp
                except:
                    pass
    for i in range(len(neib)):
        for j in range(len(neib[i])):
            neib[i][j] += mov[i][j]
    print(neib)
ans = []
for i in range(len(neib)):
    for j in range(len(neib[i])):
        ans.append(neib[i][j])
print(max(ans))
print(min(ans))
