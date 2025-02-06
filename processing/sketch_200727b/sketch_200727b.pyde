w_width = 0
w_height = 0
back_c = color(200,200,200)
color_b = color(100,100,100)
def setup():
    global w_width,w_height,back_c
    w_width = 1000
    w_height = 1000
    frameRate(10000)
    size(1000,1000)
    background(back_c)
def draw():
    global w_width,w_height
    background(back_c)
    rectMode(CENTER)
    fill(color_b)
    circle(mouseX,mouseY,100)
