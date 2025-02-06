number1 = list(input('enter a number(3 digit):'))
number2 = list(input('enter a number(3 digit):'))
answer = []
number3 = 0
number4 = 0
number1.reverse()
number2.reverse()
for i in range(0,2):
    if int(number1[i]) + int(number2[i]) > 10:
        number3+=1
        answer.insert(-1, int(number1[i])+int(number2[i])-10)
        if int(number1[i+1]) == 9 and int(number2[i+1]) == 9:
            number3 += 1
            if int(number1[i+2]) == 9 and int(number2[i+2]) == 9:
                number3 += 1
                number4 = 1000
            elif int(number1[i+2]) != 9:
                number1[i+2] = int(number1[i+2]) + 1
            else:
                number2[i+2] = int(number2[i+2]) + 1
        elif int(number1[i+1]) != 9:
            number1[i+1] = int(number1[i+1]) + 1
        else:
            number2[i+1] = int(number2[i+1]) + 1
    else:
        answer.insert(-1, int(number1[i])+int(number2[i]))
if number4 == 1000:
    answer.insert(-1, 1)
answer.reverse()
answer2 = ''
print(number3)
