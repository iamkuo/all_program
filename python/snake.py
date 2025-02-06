import turtle as t
import random
back = t.Screen()
head = t.Turtle()
head_show = t.Turtle()
head.setheading(0)
head_show.setheading(0)
head.shape('square')
head_show.shape('arrow')
head.shapesize(0.8,2.5,0.8)
head_show.shapesize(2,5,1)
head.pu()
head_show.pu()
head.goto(0,0)
head_show.goto(0,0)
apple = t.Turtle()
text = t.Turtle()
text.speed(0)
text.penup()
text.hideturtle()
text.goto(300,250)
text.write(0, move=False, align="left", font=("Arial", 30, "normal"))
apple.pu()
apple.speed(0)
back.screensize(500,500)
pressed = False
back.addshape("snake_head.gif")
back.addshape('apple.gif')
apple.shape('apple.gif')
score = 0
dat = []
face = 0
speed = 40
snake_length = 20
def up():
    global face,pressed
    if face != 270 and pressed == False:
        print('up')
        face = 90
        head.speed(0)
        head_show.speed(0)
        head.setheading(face)
        head_show.setheading(face)
        head.speed(3)
        head_show.speed(3)
        pressed = True
def down():
    global face,pressed
    if face != 90 and pressed == False:
        print('down')
        face = 270
        head.speed(0)
        head_show.speed(0)
        head.setheading(face)
        head_show.setheading(face)
        head.speed(3)
        head_show.speed(3)
        pressed = True
def left():
    global face,pressed
    if face != 0 and pressed == False:
        print('left')
        face = 180
        head.speed(0)
        head_show.speed(0)
        head.setheading(face)
        head_show.setheading(face)
        head.speed(3)
        head_show.speed(3)
        pressed = True
def right():
    global face,pressed
    if face != 180 and pressed == False:
        print('right')
        face = 0
        head.speed(0)
        head_show.speed(0)
        head.setheading(face)
        head_show.setheading(face)
        head.speed(3)
        head_show.speed(3)
        pressed = True
#main
apple.goto(random.randint(-250,250),random.randint(-250,250))
while True:
    back.listen()
    back.onkey(up, "Up")
    back.onkey(down, "Down")
    back.onkey(left, "Left")
    back.onkey(right, "Right")
    dat.append(head.stamp())
    head.fd(speed)
    head_show.speed(0)
    head_show.goto(head.xcor(),head.ycor())
    head_show.fd(30)
    head_show.speed(3)
    if len(dat) > snake_length:
        head.clearstamp(dat[0])
        dat.pop(0)
    if head_show.distance(apple.xcor(),apple.ycor()) <= 50:
        score += 1
        snake_length += 1
        apple.goto(random.randint(-250,250),random.randint(-250,250))
        text.clear()
        text.write(score, move=False, align="left", font=("Arial", 30, "normal"))
    #print(head.distance(head_show.xcor(),head_show.ycor()))
    pressed = False
        
