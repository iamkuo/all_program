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
cb = dict()
first = 0
def create_dic():
    for i in range(3):
        for j in range(3):
            cb[i,j] = -1            
def grideline():
    global w_width,w_height,gw,gh,row,col,dim,cx0,cy0
    row2 = row
    col2 = col
    gw = (w_width-spaceX)/(col*1.0)
    gh = (w_height-2*spaceY)/row*1.0
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
        fill(0)
    else:
        fill(255)
    circle(cx0+col*gw,cy0+row*gh,dim)
def setup():
    strokeWeight(2)
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
        if cb[nR,nC] < 0:
            chess(nR,nC,p)
            cb[nR,nC] = p
            if p == 0:
                p = 1
            else:
                p = 0
