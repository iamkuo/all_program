n = int(input())
ans = n
while(n >=5):
    ans += n // 5
    n = n % 5 + n // 5
print(ans+n // 5)
