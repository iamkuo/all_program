st = input("what is your birth?")
try:
    string2 = int(st)
except ValueError:
    print('enter some number')
    exit()
if len(st) != 8:
    print("enter 8 digit number")
    exit()
st = int(st)
s1 = st%10
s2 = st//10%10
s3 = st//100%10
s4 = st//1000%10
s5 = st//10000%10
s6 = st//100000%10
s7 = st//1000000%10
s8 = st//10000000%10
answer = s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8
print(answer)
