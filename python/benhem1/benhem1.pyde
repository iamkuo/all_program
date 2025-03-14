def setup():
    size(1000,1000)
    background(255)
    strokeWeight(3)
    strokeCap(SQUARE)
    noFill()
    move = 20
    stroke(255,0,0)
    strokeCap(ROUND)
    for i in range(8):
        arc(width/2-10,height/2,width/4+20*i,height/4+20*i,0+PI/10*i,PI/4+PI/10*i)
    for i in range(9):
        arc(width/2-20,height/2,width/4+140+20*i,height/4+140+20*i,PI-(PI/4+PI/10*i),PI-(PI/10*i))
    for i in range(9):
        arc(width/2-10,height/2,width/4+300+20*i,height/4+300+20*i,0+PI/10*i,PI/4+PI/10*i)
    for i in range(9):
        arc(width/2-20,height/2,width/4+460+20*i,height/4+460+20*i,PI-(PI/4+PI/10*i),PI-(PI/10*i))
    stroke(0,0,0)
    fill(0)
    circle(width/2,height/2,width/5)
    arc(width/2,height/2,width/1.1,height/1.1,PI,TAU)
    save('benhem.png')
