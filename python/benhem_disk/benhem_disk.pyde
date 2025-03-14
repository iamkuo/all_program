def lines(wide,start,bw,many):
    noStroke()
    angle = TWO_PI/many
    for i in range(0,many):
        fill(bw)
        print(bw)
        arc(width/2,height/2,wide,wide,angle*i+start,angle*(i+1)+start)
        if bw == 255:
            bw = 0
        else:
            bw = 255
def setup():
    size(1000,1000)
    lines(900,0,255,18)
    lines(800,0,0,18)
    lines(700,0,255,18)
    lines(600,0,0,18)
    lines(500,0,255,18)
    lines(400,0,0,18)
    lines(300,0,255,18)
    lines(200,0,0,18)
    lines(100,0,255,18)
    fill(0)
    stroke(0)
    strokeWeight(5)
    circle(width/2,height/2,30)
    save('pad.png')
    
