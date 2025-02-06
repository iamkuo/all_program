dat = []
b_size = None
space = 100
b_amount = 15
bomb = None
bomb_amount = None
def genarate_board():
    global b_size,b_amount,space,dat,bomb_amount
    # create dat
    for i in range(b_amount):
        dat.append([])
        for j in range(b_amount):
            dat[i].append({})
            dat[i][j]['x'] = space+b_size*i
            dat[i][j]['y'] = space+b_size*j
            dat[i][j]['type'] = 0
            dat[i][j]['open'] = False
            dat[i][j]['flag'] = False
            dat[i][j]['bomb'] = False
    dat[0][0]['open'] = False
    #random insert bomb
    bomb_amount = 20
    for i in range(bomb_amount):
        x = int(random(0,b_amount))
        y = int(random(0,b_amount))
        while dat[x][y]['bomb'] == True:
            x = int(random(0,b_amount))
            y = int(random(0,b_amount))
        dat[x][y]['bomb'] = True
        
        for i in range(x-1,x+2):
            for j in range(y-1,y+2):
                if i < 0 or j < 0:
                    continue
                if i > b_amount-1 or j > b_amount-1:
                    continue
                dat[i][j]['type'] += 1
    # show
    for i in range(b_amount):
        for j in range(b_amount):
            fill(200)
            rect(dat[i][j]['x'],dat[i][j]['y'],b_size,b_size,b_size/5)
def update_board():
    global b_size,b_amount,space,dat,flag
    # show
    background(100)
    for i in range(b_amount):
        for j in range(b_amount):
            if dat[i][j]['open'] == False:
                fill(200)
                rect(dat[i][j]['x'],dat[i][j]['y'],b_size,b_size,b_size/5)
                if dat[i][j]['flag'] == True:
                    image(flag,dat[i][j]['x'],dat[i][j]['y'],b_size,b_size)
            elif dat[i][j]['open'] == True:
                if dat[i][j]['type'] != 0:
                    fill(255,0,0)
                    textAlign(LEFT,TOP)
                    textSize(40)
                    text(str(dat[i][j]['type']),dat[i][j]['x'],dat[i][j]['y'])
def die():
    global dat,b_amount,b_size
    for i in range(b_amount):
        for j in range(b_amount):
            if dat[i][j]['bomb'] == True:
                image(bomb,dat[i][j]['x'],dat[i][j]['y'],b_size,b_size)
def spray(x,y):
    global dat,b_amount
    if dat[x][y]['type'] != 0:
        return
    check = [[x,y]]
    left = 1
    new = 0
    while left != 0:
        x = check[left-1][0]
        y = check[left-1][1]
        check.pop()
        left -= 1
        for i in range(x-1,x+2):
            for j in range(y-1,y+2):
                if i == x and j == y:
                    continue
                if i < 0 or i >= b_amount:
                    continue
                if j < 0 or j >= b_amount:
                    continue
                if dat[i][j]['bomb'] == False and dat[i][j]['open'] == False:
                    dat[i][j]['open'] = True
                    if dat[i][j]['type'] == 0:
                        check.append([i,j])
                        left += 1
def setup():
    global b_size,space,b_amount,bomb,flag
    size(1000,1000)
    background(100)
    bomb = loadImage("bomb.png")
    flag = loadImage("flag.png")
    b_size = (width-space*2)/b_amount
    genarate_board()
    print(dat)
def draw():
    pass
def mouseClicked():
    global space,b_size,dat
    pos = [(mouseX-space)/b_size,(mouseY-space)/b_size]
    if (mouseButton == LEFT):
        if dat[pos[0]][pos[1]]['open'] == 0 and dat[pos[0]][pos[1]]['flag'] == False:
            dat[pos[0]][pos[1]]['open'] = True
            spray(pos[0],pos[1])
            update_board()
            if dat[pos[0]][pos[1]]['bomb'] == True:
                update_board()
                die()
                noLoop()
            else:
                update_board()
    if (mouseButton == RIGHT):
        if dat[pos[0]][pos[1]]['flag'] == False:
            dat[pos[0]][pos[1]]['flag'] = True
        elif dat[pos[0]][pos[1]]['flag'] == True:
            dat[pos[0]][pos[1]]['flag'] = False
        update_board()
