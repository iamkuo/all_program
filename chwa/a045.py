import math
n = int(input())
ans = True
i = 2
while i * i <= n:
    if n % i == 0:
        ans = False
        print("NO")
        break
    i += 1
if ans: print("YES")