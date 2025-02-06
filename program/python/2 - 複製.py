num = int(input('enter a number(<65535):'))
lis = ''
for i in range(16):
    lis += str(num%2)
    num //= 2
print('binary ', 'b', lis)
