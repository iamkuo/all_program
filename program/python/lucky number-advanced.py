st = input("what is your birth?")
lis = []
try:
    string2 = int(st)
except ValueError:
    print('enter some number')
    exit()
if len(st) != 8:
    print("enter 8 digit number")
    exit()
st = int(st)
answer = 0
#one type:
for i in range(8):
    answer += (st%10)
    st //= 10
#second type:
'''
s1 = st%10
s2 = st//10%10
s3 = st//10//10%10
s4 = st//10//10//10%10
s5 = st//10%10
s6 = st//100000%10
s7 = st//1000000%10
s8 = st//10000000%10
'''
print(answer)
