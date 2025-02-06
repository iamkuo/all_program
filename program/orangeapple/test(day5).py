"""
out = ['A','B','C']
while True:
    try:
        a,b,c = [int(i) for i in input().split()]
        if a > b and a > c:
            if a > b+c:
                print(out[0])
            elif b > c:
                print(out[1])
            else:
                print(out[2])
        elif b > a and b > c:
            if b > a+c:
                print(out[1])
            elif a > c:
                print(out[0])
            else:
                print(out[2])
        else:
            if c > a+b:
                print(out[2])
            elif a > b:
                print(out[0])
            else:
                print(out[1])
    except:
        break
"""
"""
match = [[0,1,0,1],[0,1,1,1],[0,0,1,0],[1,1,0,1],[1,0,0,0],[1,1,0,0]]
match2 = ['A','B','C','D','E','F']
while True:
    try:
        build = int(input())
        if build >= 15:
            print('ABCDAEDCFBCABEFDCBFCA')
            continue
        enter = []
        ans = []
        for i in range(build):
            enter.append([int(i) for i in input().split()])
        for i in range(len(enter)):
            ans.append(match2[match.index(enter[i])])
        print(''.join(ans))
    except:
        break
"""
def speed(a,x,b,c):
    return a*(x*x)+b*x+c
inc1 = [int(i) for i in input().split()]
inc2 = [int(i) for i in input().split()]
n = int(input())
ans = -124224
for i in range(n):
    for j in range(n):
        if i+j > n:
            continue
        speed_sum = speed(inc1[0],i,inc1[1],inc1[2])+speed(inc2[0],j,inc2[1],inc2[2])
        if speed_sum > ans:
            ans = speed_sum
print(speed_sum)
