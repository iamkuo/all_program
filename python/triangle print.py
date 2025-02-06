
dat = int(input())
stars = 1
for i in range(dat):
    print('_'*(dat-i-1)+'*'*stars+'_'*(dat-i-1))
    stars += 2
