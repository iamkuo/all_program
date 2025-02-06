import turtle as t
dat = []
shape = []
back = t.Screen()
start = (-200,-200)
back.setup(800,800)
for i in range(10):
    dat.append([])
    for j in range(10):
        dat[i].append(t.Turtle())
        dat[i][j].shape('square')
        dat[i][j].shapesize(2,2,1)
        dat[i][j].speed(0)
        dat[i][j].penup()
        dat[i][j].goto(start[0]+50*j,start[1]+50*i)
def play(x,y):
    global dat
    dis = 10000
    tag = []
    for i in range(10):
        for j in range(10):
            if dat[i][j].distance(x,y) < dis:
                dis = dat[i][j].distance(x,y)
                tag = [i,j]
    dat[i][j].shape()
    
back.onscreenclick(play)
