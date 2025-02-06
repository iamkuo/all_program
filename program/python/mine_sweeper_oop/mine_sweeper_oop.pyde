dat = []
b_size = None
space = 100
b_amount = 10
bomb = None
bomb_amount = None
shovel = loadImage('shovel.png')
class block:
    global b_size,flag
    def __init__(self,x,y,type,has,flag,bomb):
        self.x = x
        self.y = y
        self.has = has
        self.flag = flag
        self.bomb = bomb
        self.type = type
    def spawn(self):
        fill(200)
        rect(self.x,self.y,b_size,b_size,b_size/5)
    def put_flag(self):
        image(flag,self.x,self.y,b_size,b_size)
    def number(self):
        fill(255,0,0)
        textAlign(CENTER,CENTER)
        textSize(60)
        text(str(self.type),self.x+b_size/2,self.y+b_size/2)
    def explode(self):
        image(bomb,self.x,self.y,b_size,b_size)
def genarate_board():
    global b_size,b_amount,space,dat,bomb_amount
    # create dat
    for i in range(b_amount):
        dat.append([])
        for j in range(b_amount):
            dat[i].append(block(space+b_size*i,space+b_size*j,0,False,False,False))
    #random insert bomb
    bomb_amount = 2
    for i in range(bomb_amount):
        x = int(random(0,b_amount))
        y = int(random(0,b_amount))
        while dat[x][y].bomb == True:
            x = int(random(0,b_amount))
            y = int(random(0,b_amount))
        dat[x][y].bomb = True
        
        for i in range(x-1,x+2):
            for j in range(y-1,y+2):
                if i < 0 or j < 0:
                    continue
                if i > b_amount-1 or j > b_amount-1:
                    continue
                dat[i][j].type += 1
    # show
    for i in range(b_amount):
        for j in range(b_amount):
            dat[i][j].spawn()
def update_board():
    global b_size,b_amount,space,dat,flag
    # show
    background(100)
    for i in range(b_amount):
        for j in range(b_amount):
            if dat[i][j].has == False:
                dat[i][j].spawn()
                if dat[i][j].flag == True:
                    dat[i][j].put_flag()
            elif dat[i][j].has == True:
                if dat[i][j].type != 0:
                    dat[i][j].number()
def die():
    global dat,b_amount,b_size
    for i in range(b_amount):
        for j in range(b_amount):
            if dat[i][j].bomb == True:
                dat[i][j].explode()
def spray(x,y):
    global dat,b_amount
    if dat[x][y].type != 0:
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
                if dat[i][j].bomb == False and dat[i][j].has == False:
                    dat[i][j].has = True
                    if dat[i][j].has == True:
                        check.append([i,j])
                        left += 1
def check_win():
    # global dat,b_amount,bomb_amount
    # correct_amount = 0
    # for i in range(b_amount):
    #     for j in range(b_amount):
    #         if dat[i][j].flag == True and dat[i][j].bomb == True:
    #             correct_amount += 1
    #         else:
    #             print('gg')
    #             return False
    # if correct_amount == bomb_amount:
    #     print('win')
    #     return True
    # else:
    #     print('gg')
    #     return False
    return True
def setup():
    global b_size,space,b_amount,bomb,flag,shovel
    size(1000,1000)
    background(100)
    cursor(HAND)
    bomb = loadImage("bomb.png")
    flag = loadImage("flag.png")
    
    b_size = (width-space*2)/b_amount
    genarate_board()
    print(dat)
def draw():
    pass
def mouseClicked():
    global space,b_size,dat
    pos = [(mouseX-space)//b_size,(mouseY-space)//b_size]
    if (mouseButton == LEFT):
        if dat[pos[0]][pos[1]].has == False and dat[pos[0]][pos[1]].flag == False:
            dat[pos[0]][pos[1]].has = True
            spray(pos[0],pos[1])
            update_board()
            if dat[pos[0]][pos[1]].bomb == True:
                update_board()
                die()
                noLoop()
            else:
                update_board()
    if (mouseButton == RIGHT):
        if dat[pos[0]][pos[1]].flag == False:
            dat[pos[0]][pos[1]].flag = True
            if check_win():
                noLoop()
                print('win')
                textSize(100)
                textAlign(CENTER,CENTER)
                fill(255,0,0)
                text('you win!',width/2,height/2)
        elif dat[pos[0]][pos[1]].flag == True:
            dat[pos[0]][pos[1]].flag = False
        update_board()
