a = input().split()
r,c,k,m = [int(i) for i in a]
city = []
mp = []
for i in range(r):
    city.append([])
    mp.append([])
    a = input().split()
    for j in range(c):
        city[i].append(int(a[j]))
        mp[i].append(0)
neib = [[1,0],[-1,0],[0,1],[0,-1]]
while m > 0:
    for R in range(r):
        for C in range(c):
            mp[R][C] = 0
            if city[R][C] != -1:
                for i in range(4):
                    tr = R+neib[i][0]
                    tc = C+neib[i][1]
                    if 0 <= tr and tr < r and 0 <= tc and tc < c:
                        if city[tr][tc] >= 0:
                            mp[R][C] += (city[tr][tc]//k - city[R][C]//k)
    for R in range(r):
        for C in range(c):
            if city [R][C] != -1:
                city[R][C] += mp[R][C]
    m -= 1


init = 0
for R in range(r):
    for C in range(c):
        if city[R][C] != -1:
            if init == 0:
                maxcity = city[R][C]
                mincity = city[R][C]
                init = 1
            else:
                if city[R][C] > maxcity:
                    maxcity = city[R][C]
                if city[R][C] < mincity:
                    mincity = city[R][C]
print(mincity)
print(maxcity)
