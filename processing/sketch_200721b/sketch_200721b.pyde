o = 0
w_width = 800
w_height = 800
elf_size = 50
elf_speedx = 10
elf_speedy = 0
elf_dir = 'l'
x = w_width+elf_size/2
y = w_height/2
def setup():
    background(0)
    size(800, 800)
def elf(x,y,w,h,op,mo):
    dir = ['r','d','l','u']
    op_angle = 0.0
    print(op)
    if mo ==1:
        op_angle = 0.2
    for i in xrange(4):
        if op == dir[i]:
            sv = (i/2.0+op_angle)*PI
            ev = sv + (2.0-2.0*op_angle)*PI
            break
    fill(0,255,0)
    arc(x, y, w, h, sv, ev,PIE)
dir2 = [0,180,]
'''
elf(50,50,80,80,0,HALF_PI,255, 0, 0)
'''
x = 400
y = 400
dir = 1
def draw():
    global o,x,elf_size,elf_speedx,elf_speedy
    global elf_dir,x,y,w_width,w_height
    background(0)
    elf(x,y,elf_size,elf_size,elf_dir,o)
    o = (o+1)%2
    x-=elf_speedx
    y+=elf_speedy
    if x < elf_size/2:
        elf_speedx *= -1
        elf_speedy = 0
        elf_dir = 'r'
    elif x > (w_width-elf_size/2):
        elf_speedx = 0
        elf_speedy = 10
        elf_dir = 'd'
        x = random(elf_size,w_height-elf_size)
        y = elf_size/2
    elif y > (w_height-elf_size/2):
        elf_speedx = 0
        elf_speedy *= -1
        elf_dir = 'u'
    elif y < (elf_size/2):
        elf_speedx = 10
        elf_speedy = 0
        elf_dir = 'l'
        x = w_width-elf_size/2
        y = random(elf_size,w_height-elf_size)
