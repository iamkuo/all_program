import time
def eratosthenes(start,end):
    end += 1
    prime = [True]*end
    prime[0] = False
    prime[1] = False
    for i in range(end//2):
        if prime[i]:
            for j in range(i*i,end,i):
                prime[j] = False
    prime = prime[start:]
    return prime
start = time.time()
sta = 1000
stop = 10000
prime = eratosthenes(sta,stop)
end = time.time()
print(end-start,'sec')
for i in range(sta,stop+1):
    print(i,end = ' ,')
    print(prime[i-sta])
