def setup():
    frameRate(10)
    background(51)
    size(800,800)
def elf(posx,posy,poher,pover,ang,opang,r,g,b):
        ang = float(ang)
        ang = ang/180*PI
        fill(r,g,b)
        arc(posx, posy, poher, pover, ang+opang/2, TWO_PI+(ang-opang/2),PIE)
def draw():
    background(0)
    x = random(0,700)
    y = random(0,700)
    aang = random(0,360)
    aopang = random(0,180)
    ar = random(0,220)
    ag = random(0,220)
    ab = random(0,220)
    elf(x,y,80,80,aang,aopang,ar,ag,ab)
