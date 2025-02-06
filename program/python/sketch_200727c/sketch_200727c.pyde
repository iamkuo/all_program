w_width = 0
w_height = 0
back_c = color(255,255,255)
color_b = color(100,100,100)
step_y = 0.0
g = +1.0
cir_width = 100
show_x = cir_width/2+100
show_y = 0
dia = [None,None]
pic = 0
bac = None
tree = None
treex = 0
treey = 0
co = 0
co2 = 0
def setup():
    global w_width,w_height,back_c,dia,bac,tree,cir_width,treey,show_y
    w_width = 1600
    w_height = 800
    treey = w_height-cir_width
    show_y = w_height-(cir_width/2+2)
    frameRate(60)
    size(1600,800)
    background(back_c)
    dia[0] = loadImage('dino.png')
    dia[1] = loadImage('dino2.png')
    #bac = loadImage('bac.png')
    tree = loadImage('catcus.png')
def draw():
    global w_width,w_height,show_y,show_x,step_x,step_y,g,cir_width,dia,pic,bac,treey,treex,co,co2,back_c
    background(0,153,51)
    rectMode(CENTER)
    fill(color_b)
    if co == 40:
        co = 0
        pic = (pic+1)%2
    co += 10
    image(dia[pic],show_x,show_y-50,cir_width,cir_width)
    treex -= 15
    if treex < 0:
        treex = w_width-cir_width*0.8
    image(tree,treex,treey,cir_width*0.8,cir_width)
    if abs(treex-show_x) < cir_width:
        if (show_y-50) >= (treey-cir_width)+20:
            noLoop()
            background(back_c)
            loop()
    if show_y >= w_height-cir_width/2:
        step_y *= -0.2
        show_y = w_height-cir_width/2
    if step_y > 50:
        step_y = 50
    if show_y == w_height-cir_width/2:
        step_y = 0
    step_y += g
    show_y += step_y
def keyPressed():
    global step_y,show_y,cir_width,w_height
    if key == ' ' or (keyCode == UP):
        if show_y>=w_height-(cir_width/2):
            step_y = -20
            show_y -= 5
def mousePressed():
    global step_y,show_y,cir_width,w_height
    if show_y>=w_height-(cir_width/2):
        step_y = -20
        show_y -= 5
