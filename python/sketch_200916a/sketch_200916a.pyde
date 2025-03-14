dia = []
col = []
moveNo = 0
xBall = list(range(len(dia)))
yBall = None
back_c = None
def setup():
    frameRate(30)
    global dia,col,back_c,moveNo,xBall,nxBall,pos,yBall
    xBall = []
    xLeft = 0.0
    back_c = color(100,100,100)
    size(1900,500)
    background(back_c)
    y = height/4.0
    for i in range(12):
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
        dia[i] = ndia
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
    moveNo = 0
    nxBall = []
    xLeft= 0
    for i in range(len(dia)):
        nxBall.append(int(xLeft+15+dia[pos[i]]/2.0))
        xLeft += 20+dia[pos[i]]
    yBall = [int(y)]*len(dia)
start = False
def draw():
    global dia,xBall,yBall,col,pos,moveNo,back_c,start
    mSpeed = 10
    if start:
        background(back_c)
        for moveNo in range(len(dia)):
            i = pos[moveNo]
            fill(col[i])
            onPos = 0
            yBall[i] += mSpeed
            if yBall[i] >= 3.0*height/4.0:
                yBall[i] = 3.0*height/4.0
                onPos += 1
            if nxBall[moveNo]-xBall[i] > 0:
                xBall[i]+= mSpeed
                if xBall[i] >= nxBall[moveNo]:
                    xBall[i] = nxBall[moveNo]
                    onPos += 1
            else:
                xBall[i]-= mSpeed
                if xBall[i] <= nxBall[moveNo]:
                    xBall[i] = nxBall[moveNo]
                    onPos += 1
            circle(xBall[i],yBall[i],dia[i])
def mouseClicked():
    global start
    if start:
        start = False
    else:
        start = True
    
