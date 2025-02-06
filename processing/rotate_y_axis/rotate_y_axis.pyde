pic = None
much = 0
def setup():
    global pic
    pic = loadImage('square.png')
    imageMode(CENTER)
    size(1000,1000)
    background(255)
    frameRate(60)
    imageMode(CENTER)
    fill(20)
    rect(310,310,200,200)
    rect(610,310,200,200)
    rect(310,610,200,200)
    rect(610,610,200,200)
    
    # size(1000,1000,P3D)
    # translate(width/2,height/2)
# def draw():
#     global much,pic
#     background(255)
#     much+=QUARTER_PI/3
#     rotateY(much)
#     image(pic,width/2,height/2)
def mouseClicked():
    x = mouseX
    y = mouseY
    
