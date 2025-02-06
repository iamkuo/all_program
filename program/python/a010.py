n = int(input())
i = 2
ans = []
while i ** 2 <= n:
    s = 0
    while n % i == 0:
        n //= i
        s += 1
    if s == 1:
        ans.append(str(i))
    elif s > 1:
        ans.append(str(i) + "^" + str(s))
    i += 1
if n > 1:
    ans.append(str(n))
print(" * ".join(ans))
