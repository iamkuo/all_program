w_width = 0
w_height = 0
back_c = color(255,255,255)
color_b = color(100,100,100)
step_x = 10.0
step_y = 0.0
g = +0.5
cir_width = 100
show_x = cir_width/2+10
show_y = cir_width/2+10
def setup():
    global w_width,w_height,back_c
    w_width = 500
    w_height = 1010
    frameRate(60)
    size(500,1010)
    background(back_c)
def draw():
    global w_width,w_height,show_y,show_x,step_x,step_y,g,cir_width
    background(back_c)
    rectMode(CENTER)
    fill(color_b)
    rect(show_x,show_y,cir_width,cir_width)
    if step_y > 30:
        step_y = 30
    if show_y >= w_height-cir_width/2:
        step_y*= -0.9
        show_y = w_height-cir_width/2
    if show_x >= w_width-cir_width/2 or show_x <= cir_width/2:
        step_x*= -1
    if step_y > 20:
        step_y = 20
    step_y += g
    show_y += step_y
    show_x += step_x
def mousePressed():
    global step_y,show_y,cir_width
    if pmouseX > show_x-cir_width/2 and pmouseX < show_x+cir_width/2 and pmouseY > show_y-cir_width/2 and pmouseY < show_y+cir_width/2:
        step_x = (show_x-pmouseX)
        step_y = -20
