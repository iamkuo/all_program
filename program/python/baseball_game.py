dat = []
max_len = -1
out_amount = 0
for i in range(9):
    dat.append([i for i in input().split()])
    dat[i][0] = int(dat[i][0])
    if(dat[i][0] > max_len):
        max_len = dat[i][0]
    dat[i].pop(0)
for i in range(9):
    if(len(dat[i]) < max_len):
        for j in range(max_len-len(dat[i])):
            dat[i].append(-1)
goal = int(input())
sorted_data = []
for i in range(max_len):
    for j in range(9):
        if(dat[j][i] != -1):
            sorted_data.append(dat[j][i])
i = 0
while(out_amount != goal):
    if(sorted_data[i] == "FO" or sorted_data[i] == "GO" or sorted_data[i] == "SO"):
        out_amount += 1
    i += 1
sorted_data = sorted_data[0:i]
bases = [None]*4
score = 0
out_amount = 0
for i in range(sorted_data):
    if(sorted_data[i] == "1B"):
        for j in range(3):
            if(bases[3-j] != None and 3-j+1>=4):
                score += 1
                bases.pop(3-j)
            if(bases[3-j] != None and 3-j+1<4):
                bases.pop(3-j)
                bases[3-j+1] = 1
    if(sorted_data[i] == "2B"):
        for j in range(3):
            if(bases[3-j] != None and 3-j+2>=4):
                score += 1
                bases.pop(3-j)
            if(bases[3-j] != None and 3-j+2<4):
                bases.pop(3-j)
                bases[3-j+2] = 1
    if(sorted_data[i] == "3B"):
        for j in range(3):
            if(bases[3-j] != None and 3-j+3>=4):
                score += 1
                bases.pop(3-j)
            if(bases[3-j] != None and 3-j+3<4):
                bases.pop(3-j)
                bases[3-j+3] = 1
    if(sorted_data[i] == "HR"):
        for j in range(3):
            if(bases[3-j] != None and 3-j+4>=4):
                score += 1
                bases.pop(3-j)
            if(bases[3-j] != None and 3-j+4<4):
                bases.pop(3-j)
                bases[3-j+4] = 1
    if(sorted_data[i] == "FO" or sorted_data[i] == "GO" or sorted_data[i] == "SO"):
        out_amount += 1
        if(out_amount == 3):
            bases = [None]*4
            out_amount = 0
print(score)
