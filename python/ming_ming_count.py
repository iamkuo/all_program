def count(n,m,tot):
    if tot > m:
        return 0
    return 1+count(n+1,m,tot+n)
while True:
    try:
        dat = [int(i) for i in input().split()]
        print(1+count(dat[0]+1,dat[1],dat[0]))
    except:
        break
