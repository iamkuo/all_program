w_width = 0.0
w_height = 0.0
gw = 0.0
gh = 0.0
spaceX = 52.0
spaceY = 52.0
row = 3
col = 3
color_b = color(136,71,35)
back_c = color(0,85,90)
cx0 = 0.0
cy0 = 0.0
dim = 0.0
p = 0
cb = []
con_win = row
first = 0
def create_dic():
    global cb
    for i in range(row):
        cb.append([])
        for j in range(col):
            cb[i].append(-1)
def grideline():
    global w_width,w_height,gw,gh,row,col,dim,cx0,cy0
    gw = (w_width-spaceX*2)/(col*1.0)
    gh = (w_height-spaceY*2)/(row*1.0)
    if gw > gh:
        dim = 0.8*gh
    else:
        dim = 0.8*gw
    cx0 = spaceX+gw//2.0
    cy0 = spaceY+gh//2.0
    fill(color_b)
    rect(spaceX*0.9,spaceY*0.9,w_width-1.8*spaceX,w_height-1.8*spaceY)
    for i in range(row+1):
        y = spaceY+i*gh
        line(spaceX,y,w_width-spaceX,y)
    for i in range(col+1):
        x = spaceX+i*gw
        line(x,spaceY,x,w_height-spaceY)
def chess(row,col,player):
    global cxl,cy0,gw,gh,dim
    if player == 0:
        stroke(0,0,0)
        circle(cx0+col*gw,cy0+row*gh,dim)
    else:
        dim2 = dim/2
        stroke(255,255,255)
        line((cx0+col*gw)-dim2,(cy0+row*gh)+dim2,(cx0+col*gw)+dim2,(cy0+row*gh)-dim2)
        stroke(255,255,255)
        line((cx0+col*gw)+dim2,(cy0+row*gh)+dim2,(cx0+col*gw)-dim2,(cy0+row*gh)-dim2)
def judge(cR,cC):
    global cb,con_win,p
    for j in range(4):
        linkN = 1
        for i in range(1,con_win):
            if (j == 0):#up,down
                ttr = cR + i
                ttc = cC
            elif (j == 1):#left,right
                ttr = cR
                ttc = cC + i
            elif (j == 2):#up-slop
                ttr = cR + i
                ttc = cC + i
            else:#down-slop
                ttr = cR + i
                ttc = cC - i
            if ttr < len(cb) and ttc < len(cb[0]) and ttc >= 0:
                if cb[ttr][ttc] == p:
                    linkN+=1
                    #print(linkN)
                    if linkN == con_win:
                        return True
                else:
                    break
            else:            
                break
        for i in range(1,con_win):
            if (j == 0):#up,down
                ttr = cR - i
                ttc = cC
            elif (j == 1):#left,right
                ttr = cR
                ttc = cC - i
            elif (j == 2):#up-slop
                ttr = cR - i
                ttc = cC - i
            else:#down-slop
                ttr = cR - i
                ttc = cC + i
            if ttr >= 0 and ttc >= 0 and ttc < len(cb[0]):
                if cb[ttr][ttc] == p:
                    linkN+=1
                    #print(linkN)
                    if linkN == con_win:
                        return True
                else:
                    break
            else:            
                break
def setup():
    strokeWeight(3)
    global w_width,w_height,gw,gh
    size(1024,1024)
    background(back_c)
    w_width = 1024.0
    w_height = 1024.0
    create_dic()
    grideline()
def draw():
    global spaceX,spaceY,gw,gh
#def mouseClicked():
def mousePressed():
    global spaceX,spaceY,gw,gh,p,w_width,w_height,p
    mX = mouseX
    mY = mouseY
    if (mX > spaceX) and (mX < w_width-spaceX) and (mY > spaceY) and (mY < w_height-spaceY):
        nR = int((mouseY-spaceY)//gh)
        nC = int((mouseX-spaceX)//gw)
        if cb[nR][nC] < 0:
            chess(nR,nC,p)
            if judge(nR,nC):
                ss = 'player'+str(p+1)+'win!'
                textSize(64)
                textAlign(CENTER)
                fill(100,100,100)
                text(ss,w_width/2,w_height/2)
            cb[nR][nC] = p
            if p == 0:
                p = 1
            else:
                p = 0
