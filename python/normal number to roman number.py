ro = ['I','V','X']
while True:
    n = int(input('enter a number'))
    di = 0
    d = n%10
    f = int(d/5)
    d %= 5
    if d == 4:
        d2r = ro[2*di]
        if f == 1:
            d2r += ro[2*(di+1)]
        else:
            d2r += ro[2*di+1]
    else:
        d2r = ''
        if f == 1:
            d2r = ro[2*di+1]
        for i in range(d):
            d2r += ro[2*di]
        print(d2r)
