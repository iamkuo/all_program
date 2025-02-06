from sys import stdin
from sys import setrecursionlimit
setrecursionlimit(9999999)
def f(n):
    if n == 1:
        return 1
    return n*(n+1)//2
def g(n):
    if n == 1:
        return 1
    return f(n) + g(n-1)
for i in stdin:
    i = int(i)
    print(str(f(i)) + " " + str(g(i)))