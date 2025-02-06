w_width = 0.0
w_height = 0.0
gw = 0.0
gh = 0.0
spaceX = 52.0
spaceY = 52.0
row = 16
col = 16
color_b = color(136,71,35)
back_c = color(0,85,90)
cx0 = 0.0
cy0 = 0.0
dim = 0.0
p = 0
cb = []
con_win = 5
first = 0
going = 0
show_i = 276438
times = 0
left_x = 0
left_y = 0
right_x = 0
right_y = 0
def create_dic():
    global cb
    cb = []
    for i in range(row):
        cb.append([])
        for j in range(col):
            cb[i].append(-1)
def grideline():
    global w_width,w_height,gw,gh,row,col,dim,cx0,cy0,going
    rectMode(CORNER)
    gw = (w_width-spaceX*2)/(col*1.0)
    gh = (w_height-spaceY*2)/(row*1.0)
    if gw > gh:
        dim = 0.8*gh
    else:
        dim = 0.8*gw
    cx0 = spaceX+gw//2.0
    cy0 = spaceY+gh//2.0
    fill(color_b)
    stroke(0,0,0)
    rect(spaceX*0.9,spaceY*0.9,w_width-1.8*spaceX,w_height-1.8*spaceY)
    for i in range(row+1):
        y = spaceY+i*gh
        stroke(0,0,0)
        line(spaceX,y,w_width-spaceX,y)
    for i in range(col+1):
        x = spaceX+i*gw
        stroke(0,0,0)
        line(x,spaceY,x,w_height-spaceY)
    going = 1
def chess(row,col,player):
    global cxl,cy0,gw,gh,dim,times
    times += 1
    if player == 0:
        fill(0,0,0)
    else:
        fill(255,255,255)
    circle(cx0+col*gw,cy0+row*gh,dim)
def chess2(row,col):
    global cxl,cy0,gw,gh,dim,times
    times -= 1
    noStroke()
    fill(color_b)
    circle(cx0+col*gw,cy0+row*gh,dim+4)
def setup():
    global w_width,w_height,gw,gh
    strokeWeight(3)
    size(1000,1000)
    background(back_c)
    w_width = 1000.0
    w_height = 1000.0
    create_dic()
    grideline()
def draw():
    global p
#def mouseClicked():
def mousePressed():
    global spaceX,spaceY,gw,gh,p,w_width,w_height,p,going,back_c,show_i,p,times,con_win,left_x,left_y,right_x,right_y
    mX = mouseX
    mY = mouseY
    if (mX > spaceX) and (mX < w_width-spaceX) and (mY > spaceY) and (mY < w_height-spaceY):
        nR = int((mouseY-spaceY)//gh)
        nC = int((mouseX-spaceX)//gw)
        if times == row*col:
            frameRate(2)
            ss = 'no people win!'
            textSize(64)
            textAlign(CENTER)
            fill(100,100,100)
            text(ss,w_width/2,w_height/3)
            exit()
        if cb[nR][nC] < 0:
            chess(nR,nC,p)
            cb[nR][nC] = p
            if p == 0:
                p = 1
            else:
                p = 0
def keyPressed():
    global spaceX,spaceY,gw,gh,p,w_width,w_height,p,going,back_c,show_i,p,times,con_win,left_x,left_y,right_x,right_y
    mX = mouseX
    mY = mouseY
    if key == 'x':
        if (mX > spaceX) and (mX < w_width-spaceX) and (mY > spaceY) and (mY < w_height-spaceY):
            nR = int((mouseY-spaceY)//gh)
            nC = int((mouseX-spaceX)//gw)
            if cb[nR][nC] >= 0:
                chess2(nR,nC)
                cb[nR][nC] = -1
