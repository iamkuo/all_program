x = int(input("enter a number:"))
y = int(input("enter a number:"))
math = input('do what?')
if math == '+':
    print(x,"+",y,"=",x+y,sep=' ',end='$$$$$$$$$$$$$$$')
elif math == '-':
    print(x,"-",y,"=",x-y,sep=' ',end='$$$$$$$$$$$$$$$')
elif math == '*':
    print(x,"*",y,"=",x*y,sep=' ',end='$$$$$$$$$$$$$$$')
elif math == '/':
    print(x,"/",y,"=",x/y,sep=' ',end='$$$$$$$$$$$$$$$')
elif math == '**':
    print(x,"**",y,"=",x**y,sep=' ',end='$$$$$$$$$$$$$$$')
elif math == '//':
    print(x,"//",y,"=",x//y,sep=' ',end='$$$$$$$$$$$$$$$')
else:
    print('get out, we don\'t have that')
