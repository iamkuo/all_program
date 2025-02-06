dat = input()
dat = sum([int(dat[i])*(i+1) for i in range(len(dat))])
print((10-dat%10)%10)
