def if_arm(x):
    x = str(x)
    num_len = len(str(x))
    return sum([int(x[i]) ** num_len for i in range(num_len)]) == int(x)
start,end = [int(i) for i in input().split()]
exist = False
for i in range(start,end):
    if if_arm(i):
        exist = True
        print(i,end = " ")
if not exist:
    print("none")
