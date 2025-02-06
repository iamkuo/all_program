while True:
    try:
        num = int(input())
        if num <= 10:
            ans = num*6
        elif num <= 20:
            ans = 60+(ans-10)*2
        elif num <= 40:
            ans = 80+(ans-20)*1
        else:
            ans = 100
    except:
        break
