import random
ans = random.randint(1,100)
big = 100
small = 1
times = 0
while True:
    times += 1
    guess = int(input('please guess a number from '+str(small)+' to '+str(big)))
    if guess == ans:
        print('congratulations! you made it in',times,'guess.')
        break
    elif guess > ans:
        print('too big')
        big = guess
    else:
        print('too small')
        small = guess
