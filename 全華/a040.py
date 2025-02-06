for i in range(int(input())):
    a,b = [int(i) for i in input().split()]
    if a == b: print("Case " + str(i+1) + ": " + str(0))
    else: print("Case " + str(i+1) + ": " + ["A","B"][a<b] + " " + str(max(a,b)-min(a,b)))
