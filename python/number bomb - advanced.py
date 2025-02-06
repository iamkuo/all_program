from random import randint
print('welcome to number bomb!')
pn = input('how many player?')
pwd = randint(1, 100)
answer = [0*pn]
vmax = [100*pn]
vmin = [1*pn]
survived = [0*pn]
nowplayer = [range(0,count)]
nowplyer = 0
subtract = 0
for i in range(500):
    for nowplyer in nowplayer:
        if nowplyer > 5-subtract:
            nowplyer = 1
        answer[nowplyer] = int(input('player ' + str(nowplyer) + ' ' + str(vmax[nowplyer])+' ~ '+str(vmin[nowplyer])+' guess one number'))
        if vmin[nowplyer] <= answer[nowplyer] and vmax[nowplyer] >= answer[nowplyer] :
            if answer[nowplyer] > pwd:
                print('to big')
                vmax[nowplyer] = answer[nowplyer] - 1
                survived[nowplyer] += 1
            elif answer[nowplyer] < pwd:
                print('to small')
                vmin[nowplyer] = answer[nowplyer] + 1
                survived[nowplyer] += 1
            else:
                print('boom......' + 'player ' + str(nowplayer[nowplyer]) + ' died')
                print('game over')
                exit()
        else:
            print('out of range, ', str(nowplyer), 'lost chance')
