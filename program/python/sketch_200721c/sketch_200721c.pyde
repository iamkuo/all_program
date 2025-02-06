size(900,900)
background(200,200,200)
gw = 6
gh = 6
k = gw+50/2
l = gh+50/2
m = 0
def make_background():
    global k,l,m
    for i in range(16):
        for j in range(16):
            if m == 0:
                fill(0,0,0)
            else:
                fill(255,255,255)
            circle(k,l,50)
            k += 900/16
        k = gw+50/2
        l += 900/16
        if m == 0:
            m = 1
        else:
            m = 0
def make_hor_grid():
    global gw
    for i in range(16):
        line(0,gw,900,gw)
        gh += 53
def make_ver_grid():
    global gh
    for i in range(16):
        line(gh,0,gh,900)
        gw += 53
make_background()
make_hor_grid()
make_ver_grid()
