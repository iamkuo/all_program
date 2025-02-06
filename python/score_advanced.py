def bubble_sort(sorData):
    num = list(range(1,len(inData)+1))
    for i in range(len(sorData)-1):
        for j in range(i+1,len(sorData)):
            if sorData[j] < sorData[i]:
                sorData[i],sorData[j] = sorData[j],sorData[i]
                num[i],num[j] = num[j],num[i]
    print(num)
    print(sorData)
def fast_sort(sorData):
    res = [-1]*len(sorData)
    res[0] = sorData[0]
    for i in range(1,len(sorData)):
        p = i
        res[i] = sorData[i]
        while res[p-1] > res[p] and p > 0:
            res[p-1], res[p] = res[p], res[p-1]
            p -= 1
    
    print(res)
    print(no)


inData = input('enter')
inData = inData.split(sep=" ")
#change data type
for i in range(len(inData)):
    inData[i] = float(inData[i])
minData = 1000000
minNo = -1
for i in range(len(inData)):
    if inData[i] < minData:
        minData = inData[i]
        minNo = i+1
print('Fast NO.',minNo,' => ',minData)
sorData = inData
fast_sort(sorData)
