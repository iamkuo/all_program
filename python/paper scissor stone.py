import random as r
print("*********************剪刀石頭布遊戲***********************")
try:
    human = input("出什麼拳?[0]剪刀[1]石頭[2]布")
    human = int(human)
except:
    print("請別亂打")
    exit()

computer = r.randint(0,2)
# print(computer)

if human == 0:
    print('你出剪刀')
elif human == 1:
    print('你出石頭')
elif human == 2:
    print('你出布')
else:
    print("請別亂打")
    exit()
if computer == 0:
    print('電腦出剪刀')
elif computer == 1:
    print('電腦出石頭')
elif computer == 2:
    print('電腦出布')
if human == 2 and computer == 0:
    print("電腦勝")
elif human == 0 and computer == 2:
    print("玩家勝")
elif human > computer:
    print("玩家勝")
elif human < computer:
    print("電腦勝")
elif human == computer:
    print("平手")
 



