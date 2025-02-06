string = input("what is your birth?")
try:
    string2 = int(string)
except ValueError:
    print('enter a number')
    exit()
if len(string) != 8:
    print("enter 8 digit number")
    exit()
number2 = len(string)
def split(word): 
    return [char for char in word]
number = split(string)
answer = 0
for i in range(number2):
        answer = answer + int(number[i])
print(answer)
