bx = []
by = []
speedx = []
speedy = []
bcolor = []
crash = []
bsize = 80
balls = 20
def setup():
    global bx,by,speedx,speedy,bcolor,balls
    noStroke()
    size(1800,900)
    for i in range(balls):
        bx.append(random(0+bsize/2,width-bsize/2))
        by.append(random(0+bsize/2,height-bsize/2))
        bcolor.append(color(random(100,255),random(100,255),random(100,255)))
        speedx.append(random(-20,20))
        speedy.append(random(-20,20))
def draw():
    global bx,by,speedx,speedy,bcolor,bsize
    background(255)
    for i in range(len(bx)):
        if bx[i] + speedx[i] >= width:
            bx[i] = width-bsize/2
            speedx[i] *= -1
        elif bx[i] + speedx[i] <= 0:
            bx[i] = 0+bsize/2
            speedx[i] *= -1
        else:
            bx[i] += speedx[i]
        if by[i] + speedy[i] >= height:
            by[i] = height-bsize/2
            speedy[i] *= -1
        elif by[i] + speedy[i] <= 0:
            by[i] = 0+bsize/2
            speedy[i] *= -1
        else:
            by[i] += speedy[i]
        speedx[i]*=0.99
        speedy[i]*=0.99
    for i in range(len(bx)):
        for j in range(i+1):
            bi = ((bx[i]-bx[j])*(bx[i]-bx[j])+(by[i]-by[j])*(by[i]-by[j]))
            if bi < bsize*bsize:
                speedx[i],speedx[j] = speedx[j],speedx[i]
                speedy[i],speedy[j] = speedy[j],speedy[i]
                
                speedx[i] *= -1
                speedx[j] *= -1
                speedy[i] *= -1
                speedy[j] *= -1
                speedx[i]*=0.99
                speedy[i]*=0.99
    for i in range(len(bx)):
        fill(bcolor[i])
        circle(bx[i],by[i],bsize)
