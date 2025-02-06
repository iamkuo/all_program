background(200)
size(200, 200)
def elf(posx,posy,poher,pover,ang,opang,r,g,b):
        ang = float(ang)
        ang = ang/180*PI
        fill(r,g,b)
        arc(posx, posy, poher, pover, ang+opang/2, TWO_PI+(ang-opang/2),PIE)
elf(50,50,80,80,0,HALF_PI,255, 0, 0)
elf(150,50,80,80,90,HALF_PI,0,255,0)
elf(50,150,80,80,180,HALF_PI,0,0,255)
elf(150,150,80,80,270,HALF_PI,250,250,0)
