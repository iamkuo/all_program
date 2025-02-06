num = int(input('enter a number(<65535):'))
lis = ''
for i in range(4):
    dig = num%16
    if dig <= 9:
        lis = str(dig)+lis
    elif dig == 10:
        lis = 'a'+lis
    elif dig == 11:
        lis = 'b'+lis
    elif dig == 12:
        lis = 'c'+lis
    elif dig == 13:
        lis = 'd'+lis
    elif dig == 14:
        lis = 'e'+lis
    else:
        lis = 'f'+lis
    num //= 16
    #print(ln)
print('hex ', '0x', lis)
