'''
trash = int(input())
while True:
    try:
        enter = input()
        ans = int(enter[::-1])
        print(ans)
    except:
        break
'''
'''
enter = [int(i) for i in input().split()]
be_divide = list(str(enter[0]))
to_divide = enter[1]
end = None
ans = []
while not end:
    end = True
    
'''
'''
form = [int(i) for i in input().split()]
dat = [int(i) for i in input().split()]
for i in range(form[1]):
    where = [int(i) for i in input().split()]
    print(sum(dat[where[0]-1:where[1]]))
'''
'''
while True:
    trash = input()
    if trash != 0:
        dat = [int(i) for i in input().split()]
        many = sum(dat)
        height = many/len(dat)
        ans = 0
        for i in range(len(dat)):
            if dat[i] > height:
                ans += dat[i] - height
        print(ans)
    else:
        break
'''
'''
degrees = int(input())
text = input()
print('今天的天氣是{degrees}度，天氣是{text}天'.format(degrees=degrees,text=text))
print('今天的天氣是%d度，天氣是%s天'%(degrees,text))
'''
'''
while True:
    dat = [int(i) for i in input().split()]
'''
'''
import string
dat = list(input())
ans = ''
for i in range(len(dat)):
    if dat[i] not in string.punctuation:
        ans += dat[i]
    else:
        if dat[i] == '.' or dat[i] == ',' or dat[i] == '!':
            ans += dat[i]
        else:
            pass
print(ans)
'''
out = ['lucky ball','lucky sheep','lucky guy','ok','good luck']
while True:
    try:
        enter =[ord(i) for i in list(input())]
        odd = sum(enter[::2])
        even = sum(enter[1::2])
        ans = abs(odd-even)%5
        print(out[ans])
    except:
        break
