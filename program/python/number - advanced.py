x = int(input('enter a number:'))
y = int(input('enter a number:'))
#maxdig = (len(x)>len(y)) and len(x) or len(y)
#x = int(x)
#y = int(y)
upd = 0
answer = 0
#for i in range(maxdig):
while (x+y>0):
    dsum = x%10+y%10+upd
    if dsum >= 10:
        answer += 1
        upd = dsum // 10
    else:
        upd = 0
    x //= 10
    y //= 10
print(answer)
