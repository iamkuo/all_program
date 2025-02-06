dia = []
col = []
moveNo = 0
xBall = list(range(len(dia)))
back_c = None
def setup():
    global dia,col,back_c,moveNo,xBall,nxBall,pos
    xBall = []
    xLeft = 0.0
    back_c = color(100,100,100)
    size(1500,500)
    background(back_c)
    y = height/4.0
    for i in range(10):
        col.append(color(int(random(0,25))*10,int(random(0,25))*10,int(random(0,25))*10))
        dia.append(int(random(3,15)*10))
        rep = 1
        ndia = int(random(3,15)*10)
        while (rep == 1):
            ndia = int(random(3,15)*10)
            rep = 0
            for j in range(i):
                if ndia == dia[j]:
                    rep = 1
                    break
        dia.append(ndia)
        xBall.append(int(xLeft+15+dia[i]/2.0))
        fill(col[i])
        circle(xBall[i],y,dia[i])
        xLeft += dia[i]+15
    tt = [0]*len(dia)
    pos = list(range(len(dia)))
    for i in range(len(dia)):
        tt[i] = dia[i]
    for i in range(len(dia)-1):
        for j in range(i+1,len(dia)):
            if tt[j] < tt[i]:
                tt[j],tt[i] = tt[i],tt[j]
                pos[j],pos[i] = pos[i],pos[j]
    print(dia)
    print(tt)
    print(pos)
    moveNo = 0
    nxBall = []
    xLeft= 0
    for i in range(len(dia)):
        nxBall.append(int(xLeft+15+dia[pos[i]]/2.0))
        xLeft += 20+dia[pos[i]]
    yball = [y]*len(dia)
def draw():
    global dia,xBall,col,pos,moveNo,back_c
    background(back_c)
    for i in range(len(dia)):
        fill(col[i])
        if i == pos[moveNo]:
            yball[i] += 1
            onpos = 0
            if yball[i] >= 3.0*height/4.0:
                yball[i] = 3.0*height/4.0
                onpos += 1
            if nxBall[i]-xBall[i] > 0:
                xBall[i]+= 1
                if xBall[i] <= nxBall[i]:
                    xBall[i] = nxBall[i]
                    onPos += 1
            else:
                xBall[i]-= 1
                if xBall[i] <= nxBall[i]:
                    xBall[i] = nxBall[i]
                    onPos += 1
                
            circle(xBall[i],yBall[i],dia[i])
        else:
            circle(xBall[i],yBall[i],dia[i])
