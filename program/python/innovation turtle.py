import turtle as tu
tu.colormode(255)
tu.register_shape('jet',((0,0),(2,-2),(2,-4),(7,-9),(-7,-9),(-2,-4),(-2,-2)))
tu.register_shape('block',((5,5),(-5,5),(-5,-5),(5,-5)))
def sprite(shape='jet',x=0,y=0,color=(0,0,0),face=0,size=(2,5,1)):
    obj = tu.Turtle()
    obj.speed(0)
    obj.shape(shape)
    obj.goto(x,y)
    obj.shapesize(size[0],size[1],size[2])
    obj.fillcolor(color[0],color[1],color[2])
    obj.pencolor(color[0],color[1],color[2])
    obj.setheading(face)
    obj.penup()
    return obj
def check_edge(obj=[],size=150):
    for i in range(len(obj)):
        if obj[i].xcor() >= size or obj[i].xcor() <= size*-1 or obj[i].ycor() >= size or obj[i].ycor() <= size*-1:
            obj[i].rt(180)
plane = sprite(color=(255,0,0))
block = sprite(shape='block',color=(0,0,100),face = 270,size=(1,1,1))
while True:
    plane.fd(15)
    block.fd(10)
    check_edge([plane,block])
