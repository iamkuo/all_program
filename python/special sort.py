def bubble_sort(sorData):
    for i in range(len(sorData)-1):
        ss = num[i]%2
        for j in range(i+1,len(sorData)):
            if num[j]%2 == ss:
                if ss == 0:
                    if sorData[j] < sorData[i]:
                        sorData[i],sorData[j] = sorData[j],sorData[i]
                else:
                    if sorData[j] > sorData[i]:
                        sorData[i],sorData[j] = sorData[j],sorData[i]
    return sorData
num = [int(tmp) for tmp in input('enter lots of number').split()]
bubble_sort(num)
print(num)
