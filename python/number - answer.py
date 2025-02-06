x = input('enter a number:')
y = input('enter a number:')
if len(x)>len(y):
    maxdig = len(y)
else:
    maxdig = len(x)
#maxdig = (len(x)>len(y)) ? len(x):len(y)
x = int(x)
y = int(y)
upd = 0
answer = 0
for i in range(maxdig):
    dsum = x%10+y%10+upd
    if dsum >= 10:
        answer += 1
        upd = dsum // 10
    else:
        upd = 0
    x //= 10
    y //= 10
print(answer)
