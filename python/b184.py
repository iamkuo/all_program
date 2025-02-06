v_lim = 100
while "yee" == "yee":
    try:
        k = int(input())
        dp = [0]*(v_lim+1)
        for i in range(k):
            v,c = [int(i) for i in input().split()]
            for j in range(v_lim,-1,-1):
                if v <= j: dp[j] = max(dp[j],dp[j-v]+c)
        print(dp[100])
    except:
        break
