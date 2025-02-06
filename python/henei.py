import turtle as tu
import sys
import random
sys.setrecursionlimit(2000000)
tower = tu.Turtle()
scr = tu.Screen()
scr.bgcolor('#ff00ff')
dat = []
clickTimes = 0
ongoing = 0
class plate():
    def __init__(self,no):
        self.no = no
        self.__color = ['#{:02x}{:02x}{:02x}'.format(random.randint(1,254),random.randint(1,254),random.randint(1,254)) for i in range(100)]
        self.__obj = tu.Turtle()
        self.__obj.up()
        self.__obj.setheading(-90)
        self.__obj.speed(0)
        self.__obj.shape('square')
        self.__obj.shapesize((self.no+1)+0.5,1,1)
        self.__obj.fillcolor(self.__color[no])
        self.__obj.pencolor(self.__color[no])
        self.color = self.__color[self.no]
        self.X = 0
        self.Y = 0
    def go(self,x,y):
        self.__obj.goto(x,y)
        self.X = x
        self.Y = y
    def setspeed(self,x):
        self.speed = x
class tower():
    upPlateNo = -1
    def __init__(self,x1,y1,x2,y2,x3,y3,height=250):
        self.__scr = tu.Screen()
        self.content=[[],[],[],[]]
        self.towerx = [x1,x2,x3]
        self.towery = [y1,y2,y3]
        self.buttomy=[y1+18,y2+18,y3+18]
        self.height = height
        tu.pencolor('black')
        tu.pensize(15)
        tu.speed(10)
        tu.ht()
        for i in range(3):
            tu.up()
            tu.goto(self.towerx[i],self.towery[i]+self.height)
            tu.pd()
            tu.goto(self.towerx[i],self.towery[i])
            tu.goto(self.towerx[i]+100,self.towery[i])
            tu.goto(self.towerx[i]-100,self.towery[i])
    def put(self,tower,plate):
        tn = len(self.content[tower])
        if tn == 0 or self.content[tower][tn-1] > plate:
            self.content[tower].append(plate)
            self.buttomy[tower] += 20
            return True
        return False
    def take(self,tower):
        tn = len(self.content[tower])
        if tn == 0:
            return False
        self.upPlateNo = self.content[tower][tn-1]
        self.content[tower].pop()
        self.buttomy[tower] -= 20
        return True
    def isclick(self,x,y):
        tn = -1
        for i in range(3):
            if abs(x-self.towerx[i]) <= 70:
                tn = i
                break
        return tn
def playing(x,y):
    global clickTimes,ongoing
    tn = tower.isclick(x,y)
    if tn >=0 and ongoing == 0:
        ongoing = 1
        if clickTimes == 0 and tower.take(tn):
            clickTimes = 1
            pt[tower.upPlateNo].go(tower.towerx[tn],tower.towery[tn]+tower.height)
        elif clickTimes == 1 and tower.put(tn,tower.upPlateNo):
            clickTimes = 0
            pt[tower.upPlateNo].go(tower.towerx[tn],tower.towery[tn]+tower.height)
            pt[tower.upPlateNo].go(tower.towerx[tn],tower.buttomy[tn]-20)
        ongoing = 0

tower = tower(-500,-350,0,-350,500,-350,700)
plateno = int(input('how many plate?'))
pt = [0]*plateno
for i in range(plateno):
    pt[plateno-1-i] = plate(plateno-1-i)
    pt[plateno-1-i].go(tower.towerx[0],tower.towery[0]+tower.height+40)
    pt[plateno-1-i].go(tower.towerx[0],tower.buttomy[0])
    tower.put(0,plateno-1-i)
#scr.onclick(playing)
move=[]
def moveto(tn1,tn2):
    tower.take(tn1)
    pt[tower.upPlateNo].go(tower.towerx[tn1],tower.towery[tn1]+tower.height)
    tower.put(tn2,tower.upPlateNo)
    pt[tower.upPlateNo].go(tower.towerx[tn2],tower.towery[tn2]+tower.height)
    pt[tower.upPlateNo].go(tower.towerx[tn2],tower.buttomy[tn2]-20)
def caltower(platenum,curtn,tartn):
    pretn=3-curtn-tartn
    if platenum == 1:
        move.append([curtn,tartn])
        moveto(curtn,tartn)
        return
    caltower(platenum-1,curtn,pretn)
    caltower(1,curtn,tartn)
    caltower(platenum-1,pretn,tartn)
caltower(plateno,0,2)
