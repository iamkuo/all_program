n = int(input())
math = [int(i) for i in input().split()]
math_avg = sum(math)/n
en = [int(i) for i in input().split()]
en_avg = sum(en)/n
yes = False
for i in range(n):
    if math[i] >= math_avg and en[i] >= en_avg:
        print(i+1,end = " ")
        yes = True
if not yes:
    print("NO")
