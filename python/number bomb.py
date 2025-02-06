from random import randint
print('welcome to number bomb!')
pwd = randint(1, 100)
answer = 0
vmax = 100
vmin = 0
survived = 0
for i in range(100):
    answer = int(input(str(vmax)+' ~ '+str(vmin)+' guess one number'))
    if (vmin <= answer) and (vmax >=answer):
        if answer > pwd:
            print('to big')
            vmax = answer - 1
            survived += 1
        elif answer < pwd:
            print('to small')
            vmin = answer + 1
            survived += 1
        else:
            print('boom......you died')
            print('you survived', survived, 'times')
            break
    else:
        print('out of range')
    
