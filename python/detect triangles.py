def fast_sort(sorData):
    res = [-1]*len(sorData)
    res[0] = sorData[0]
    for i in range(1,len(sorData)):
        p = i
        res[i] = sorData[i]
        while res[p-1] > res[p] and p > 0:
            res[p-1], res[p] = res[p], res[p-1]
            p -= 1
    return res
try:
    num = [int(lst) for lst in input('please enter three number').split()]
except:
    print('get out')
    exit()
if len(num) != 3:
    print('get out')
    exit()
print(num)
typ = ['鈍角','直角','銳角']
ans = None
num = fast_sort(num)
print(num)
two = num[0]*num[0]+num[1]*num[1]
one = num[2]*num[2]
if num[2] < num[1] + num[0]:
    if two < one:
        ans = typ[0]
    if two == one:
        ans = typ[1]
    if two > one:
        ans = typ[2]
    print('True')
    print(ans)
else:
    print('False')
