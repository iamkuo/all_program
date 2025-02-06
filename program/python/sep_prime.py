def isprime(num):
    prime = True
    for i in range(2,int(num/2)+1):
        if num % i == 0:
            prime = False
    return prime
def minprime(num):
    if isprime(num):
        lis = []
        lis.append(num)
        lis.append(1)
        return lis
    else:
        tmp = 2
        while tmp < int(num/2)+1:
            if num % tmp == 0 and isprime(tmp):
                lis = []
                lis.append(tmp)
                lis.append(int(num/tmp))
                return lis
            tmp += 1
num = int(input())
ans = list()
if isprime(num):
    print(num)
else:
    tmp = minprime(num)
    ans.append(tmp[0])
    while tmp[1] != 1:
        tmp = minprime(tmp[1])
        ans.append(tmp[0])
    print(ans)
