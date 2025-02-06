def setup():
    size(1000,1000)
    background(255)
    fill(255)
    circle(width/2,height/2,950)
    start = 255
    for i in range(0,8):
        fill(start)
        arc(width/2,height/2,950,950,QUARTER_PI*i,QUARTER_PI*(i+1))
        if start == 255:
            start = 0
        else:
            start = 255
    start = 255
    noStroke()
    for i in range(0,8):
        fill(start)
        arc(width/2,height/2,650,650,HALF_PI*i,HALF_PI*(i+1))
        if start == 255:
            start = 0
        else:
            start = 255
    fill(0)
    arc(width/2,height/2,400,400,PI+HALF_PI,TAU)
    arc(width/2,height/2,300,300,PI,TAU)
    fill(255)
    arc(width/2,height/2,300,300,HALF_PI,PI)
    save('helmholtz.png')
