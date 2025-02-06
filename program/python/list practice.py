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
#bubble sort
num = list(range(1,len(inData)+1))
for i in range(len(sorData)-1):
    for j in range(i+1,len(sorData)):
        if sorData[j] < sorData[i]:
            sorData[i],sorData[j] = sorData[j],sorData[i]
            num[i],num[j] = num[j],num[i]
print(num)
print(sorData)
