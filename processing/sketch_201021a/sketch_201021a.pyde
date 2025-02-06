pos = []
abc = [['a','e','i','m'],['b','f','j','n'],['c','g','k','o'],['d','h','l','']]
exact = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','']
space = 10
nx = 4
ny = 4
grid = 100
space = 10
k = 101
steps = 0
mouseenable = 1
stage = 2
check_key = 0
together = 0
def chess_color(x,y):
    if abs(pos[x][y]) == 1:
        fill(80)
    if abs(pos[x][y]) == 2:
        fill(255,0,0)
    if abs(pos[x][y]) == 3:
        fill(0,0,255)
def check_rule(x,y,dir,type=1):
    global pos
    move = True
    #print(x,y)
    if pos[x][y] == 2:
        move = False
    if pos[x][y] == 3 and dir < 2:
        move = False
    if pos[x][y] == 4 and dir >= 2:
        move = False
    return move
def check():
    global abc,pos,nx,ny,exact
    win = True
    for i in range(nx*ny-1):
        if abc[i%4][i//4] != exact[i]:
            win = False
            return win
    return win
def shuffle():
    global pos,nx,ny,abc
    print(pos,abc)
    bx = nx-1
    by = ny-1
    i = 0
    chaos = 1000
    move = 0
    while i < chaos:
        #print(i)
        dir = int(random(4))
        if dir == 0:#up
            tbx = bx
            tby = by - 1
        elif dir == 1:#down
            tbx = bx
            tby = by + 1
        elif dir == 2:#right
            tbx = bx + 1
            tby = by
        else:#left
            tbx = bx - 1
            tby = by
        #print(dir,tbx,tby,bx,by)
        if tbx >= 0 and tbx < nx and tby >= 0 and tby < ny:
            if check_rule(tbx,tby,dir):
                chk = pos[tbx][tby]
                abc[bx][by],abc[tbx][tby] = abc[tbx][tby],abc[bx][by]
                pos[bx][by],pos[tbx][tby] = pos[tbx][tby],pos[bx][by]
                bx = tbx
                by = tby
                if chk == 3:
                    if dir == 2:
                        tbx = bx - 1
                        tby = by
                    else:
                        tbx = bx + 1
                        tby = by
                    abc[bx][by],abc[tbx][tby] = abc[tbx][tby],abc[bx][by]
                    pos[bx][by],pos[tbx][tby] = pos[tbx][tby],pos[bx][by]
                    bx = tbx
                    by = tby
                i += 1
    print('ok')
    # while by < ny-1:
    #     tbx = bx
    #     tby = by+1
    #     if not check_rule(tbx,tby,dir):
    #         tby = by
    #         movex = 1
    #         if bx == 3:
    #             movex = -1
    #             if pos[bx-1][by+1] == 3:
    #                 movex = -2
    #             tbx = bx-1
    #         else:
    #             if pos[bx+1][by+1] == 3:
    #                 movex = -1
    #         tbx = bx+movex
    #     abc[bx][by],abc[tbx][tby] = abc[tbx][tby],abc[bx][by]
    #     pos[bx][by],pos[tbx][tby] = pos[tbx][tby],pos[bx][by]
    #     bx = tbx
    #     by = tby
    # while bx < nx-1:
    #     tbx = bx+1
    #     tby = by
    #     abc[bx][by],abc[tbx][tby] = abc[tbx][tby],abc[bx][by]
    #     pos[bx][by],pos[tbx][tby] = pos[tbx][tby],pos[bx][by]
    #     bx = tbx
    #     by = tby
    print(abc)
def put_chesses(nx,ny,grid,space):
    global pos,abc,stage
    pos = []
    for i in range(nx):
        pos.append([])
        for j in range(ny):
            pos[i].append(0)
            if i + j != (nx+ny-2):
                pos[i][j] = 1
    if stage == 1:
        pos[int(random(0,4))][int(random(1,3))] = 2
    elif stage == 2:
        tx = int(random(0,4))
        ty = int(random(1,3))
        pos[tx][ty] = 3
        tx += 1
        if tx >= nx-1:
            tx -= 1
        print(pos)
        print(tx,ty)
        pos[tx][ty] = 3
    shuffle()
    for i in range(nx):
        for j in range(ny):
            if pos[i][j] > 0:
                chess_color(i,j)
                rect(space+i*grid,space+j*grid,grid,grid,10)
                fill(255)
                textSize(50)
                textAlign(CENTER)
                text(abc[i][j],(space+(i+0.5)*grid),(space+(j+0.6)*grid))
    fill(80)
def redraw_chesses(cx,cy,tcx,tcy):
    global pos,nx,ny,grid,space
    background(200)
    for k in range(101):#100 times loop
        for i in range(nx):
            for j in range(ny):
                if pos[i][j] == 1:
                    fill(80)
                    rect(space+i*grid,space+j*grid,grid,grid,10)
        rect((space+cx*grid)+k*(tcx-cx)*grid/100,(space+cy*grid)+k*(tcy-cy)*grid/20,grid,grid,10)
    pos[tcx][tcy] = 1
def setup():
    global pos,space,nx,ny,grid,space,stage
    strokeWeight(2)
    size(420,420)
    put_chesses(nx,ny,grid,space)
    k = steps + 1
    print(pos)
def draw():
    global pos,nx,ny,grid,space,cx,cy,tcx,tcy,k,mouseenable,abc,check_key,steps,stage,togethert,scx,scy
    step = 10
    dg = grid/step
    if k <= step:
        background(200)
        for i in range(nx):
            for j in range(ny):
                if pos[i][j] > 0:
                    chess_color(i,j)
                    rect(space+i*grid,space+j*grid,grid,grid,10)
                    fill(255)
                    textSize(50)
                    textAlign(CENTER)
                    text(abc[i][j],(space+(i+0.5)*grid),(space+(j+0.6)*grid))
        chess_color(cx,cy)
        if k == step:
            rect((space+tcx*grid),(space+tcy*grid),grid,grid,10)
            fill(255)
            textSize(50)
            textAlign(CENTER)
            text(abc[cx][cy],(space+(tcx+0.5)*grid),(space+(tcy+0.6)*grid))
            pos[cx][cy],pos[tcx][tcy] = -1*pos[tcx][tcy],-1*pos[cx][cy]
            abc[cx][cy],abc[tcx][tcy] = abc[tcx][tcy],abc[cx][cy]
            print(abc)
            print(pos)
            fill(80)
            if together == 1:
                chess_color(scx,scy)
                rect((space+cx*grid),(space+cy*grid),grid,grid,10)
                fill(255)
                textSize(50)
                textAlign(CENTER)
                text(abc[scx][scy],(space+(cx+0.5)*grid),(space+(cy+0.6)*grid))
                pos[cx][cy],pos[scx][scy] = -1*pos[scx][scy],-1*pos[cx][cy]
                abc[cx][cy],abc[scx][scy] = abc[scx][scy],abc[cx][cy]
                print(abc)
                print(pos)
                fill(80)
            if check():
                fill(0,0,255)
                textSize(32)
                textAlign(CENTER)
                text('you spend'+str(steps)+'steps!',space+nx/2*grid,space+ny/2*grid)
                text('press a for next stage!',space+nx/2*grid,(space+ny/2*grid)+30)
                check_key = 1
            else:
                mouseenable = 1
        else:
            xx = (space+cx*grid)+k*(tcx-cx)*dg
            yy = (space+cy*grid)+k*(tcy-cy)*dg
            rect(xx,yy,grid,grid,10)
            fill(255)
            textSize(50)
            textAlign(CENTER)
            text(abc[cx][cy],xx+grid/2,yy+3*grid/5)
            if together == 1:
                chess_color(scx,scy)
                xx = (space+scx*grid)+k*(cx-scx)*dg
                yy = (space+scy*grid)+k*(cy-scy)*dg
                rect(xx,yy,grid,grid,10)
                fill(255)
                textSize(50)
                textAlign(CENTER)
                text(abc[scx][scy],xx+grid/2,yy+3*grid/5)
        k += 1
    else:
        if check_key == 1:
            if keyPressed:
                if key == 'a' or key == 'A':
                    check_key = 0
                    steps = 0
                    stage += 1
                    shuffle()
                    put_chesses(nx,ny,grid,space)
                    mouseenable = 1
def mousePressed():
    global pos,space,nx,ny,grid,space,k,cx,cy,tcx,tcy,k,mouseenable,steps,together,scx,scy
    if mouseenable == 1:
        cx = int((mouseX-space)/grid)
        cy = int((mouseY-space)/grid)
        print(cx,cy)
        dir = 0
        move = 0
        for dir in range(4):
            if dir == 0:#up
                tcx = cx
                tcy = cy - 1
            elif dir == 1:#down
                tcx = cx
                tcy = cy + 1
            elif dir == 2:#right
                tcx = cx + 1
                tcy = cy
            else:#left
                tcx = cx - 1
                tcy = cy
            if (tcx >= 0 and tcx < nx) and (tcy >= 0 and tcy < ny):
                if pos[tcx][tcy] == 0:
                    if check_rule(cx,cy,dir):
                        move = 1
                        break
        if move == 1:
            mouseenable = 0
            together = 0
            if pos[cx][cy] == 3:
                together = 1
                if dir == 2:
                    scx = cx-1
                    scy = cy
                else:
                    scx = cx+1
                    scy = cy
                pos[scx][scy] *= -1
            pos[tcx][tcy] *= -1
            pos[cx][cy] *= -1
            k = 0
            steps += 1
            #redraw_chesses(cx,cy,tcx,tcy)
