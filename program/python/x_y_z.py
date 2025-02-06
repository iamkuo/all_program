def f(x):
    return 2*x-3
def g(x,y):
    return 2*x+y-7
def h(x,y,z):
    return 3*x-2*y+z
enter = input().split()
n = len(enter)
for i in range(n):
    if enter[n-1-i] == 'f':
        x = enter[n-1-i+1]
        enter[n-1-i] = f(x)
        enter.pop(n-1-i+1)
    elif enter[n-1-i] == 'g':
        x = enter[n-1-i+1]
        y = enter[n-1-i+2]
        enter[n-1-i] = g(x,y)
        enter.pop(n-1-i+1)
        enter.pop(n-1-i+1)
    elif enter[n-1-i] == 'h':
        x = enter[n-1-i+1]
        y = enter[n-1-i+2]
        z = enter[n-1-i+3]
        enter[n-1-i] = h(x,y,z)
        enter.pop(n-1-i+1)
        enter.pop(n-1-i+1)
        enter.pop(n-1-i+1)
    else:
        enter[n-1-i] = int(enter[n-1-i])
print(enter[0])
