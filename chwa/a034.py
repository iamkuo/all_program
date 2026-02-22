import math
x1,y1,x2,y2 = [int(i) for i in input().split()]
print(round(math.sqrt(abs(x1-x2)**2)+math.sqrt(abs(y1-y2)**2),3))
