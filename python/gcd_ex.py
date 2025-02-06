a,b = sorted([int(i) for i in input().split()],reverse = True)
while b:
    a,b = b,a%b
print(a)
    
