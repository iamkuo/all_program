from random import randint
from random import shuffle
def ranum():
    tmp = [1,2,3,4,5,6,7,8,9]
    shuffle(tmp)
    for i in range(4):
        answer.append(tmp[i])
def check():
    global a, b
    a = 0
    b = 0
    for i in range(4):
            if int(answer[i]) == int(tmp3[i]):
                a = a + 1
            for j in range(4):
                if int(answer[i]) == int(tmp3[j]):
                    b = b + 1
def start():
    global times, answer
    times = 0
    answer = []
    ranum()
    print(answer)
    print('welcome to 1a2b!')
    global player
    player = int(input('the game is on, guess a number(4 digit):'))
    tmp2 = list(str(player))
    tmp4 = 0
    for i in range(4):
        if int(answer[i]) == int(tmp2[i]):
            tmp4 += 1
    if tmp4 == 4:
        print('you win! you guess it in 1 times, so amazing!')
        exit()
#main
start()
while True:
    tmp3 = list(str(player))
    times += 1
    check()
    if a == 4 and b == 4:
        break
    print(a, 'a', b, 'b')
    player = int(input(str(times+1)+' th guess,kept guess a number(4 digit):'))
print('you win! you guess it in ', times, ' times.')
