dat = []
dir_dat = [[0,-1],[-1,0],[0,1],[1,0]]
n = int(input())
face = int(input())
for i in range(n):
    dat.append([int(i) for i in input().split()])
row = n//2
col = row
print(dat[row][col],end='')
cyc = 2
while cyc < n:
    for i in range(4):
        for j in range(cyc):
            if i+j == 0:
                row += dir_dat[face][0]
                col += dir_dat[face][1]
                face = (face+1)%4
            else:
                row += dir_dat[face][0]
                col += dir_dat[face][1]
            print(dat[row][col],end='')
        face = (face+1)%4
    face = (face-1)%4
    cyc += 2
