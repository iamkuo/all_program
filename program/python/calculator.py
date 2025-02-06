from tkinter import *
cal = Tk()
cal.title("calculator")
cal.geometry('350x200')
ans = Label(cal,text='')
ans.grid(column=0,row=0,columnspan=10)
def add(x):
    global ans
    ans['text'] += x
def make_ans():
    global ans
    try:
        ans['text'] = str(eval(ans['text']))
    except:
        pass
def clear():
    global ans
    ans['text'] = ''
tap_1 = Button(cal,text='1',command=lambda:add('1'),height=5,width=10)
tap_1.grid(column=0,row=1)

tap_2 = Button(cal,text='2',command=lambda:add('2'),height=5,width=10)
tap_2.grid(column=1,row=1)

tap_3 = Button(cal,text='3',command=lambda:add('3'),height=5,width=10)
tap_3.grid(column=2,row=1)

tap_4 = Button(cal,text='4',command=lambda:add('4'),height=5,width=10)
tap_4.grid(column=3,row=1)

tap_5 = Button(cal,text='5',command=lambda:add('5'),height=5,width=10)
tap_5.grid(column=4,row=1)

tap_6 = Button(cal,text='6',command=lambda:add('6'),height=5,width=10)
tap_6.grid(column=5,row=1)

tap_7 = Button(cal,text='7',command=lambda:add('7'),height=5,width=10)
tap_7.grid(column=6,row=1)

tap_8 = Button(cal,text='8',command=lambda:add('8'),height=5,width=10)
tap_8.grid(column=7,row=1)

tap_9 = Button(cal,text='9',command=lambda:add('9'),height=5,width=10)
tap_9.grid(column=8,row=1)

tap_0 = Button(cal,text='0',command=lambda:add('0'),height=5,width=10)
tap_0.grid(column=9,row=1)

tap_add = Button(cal,text='+',command=lambda:add('+'),height=5,width=10)
tap_add.grid(column=0,row=2)

tap_minus = Button(cal,text='-',command=lambda:add('-'),height=5,width=10)
tap_minus.grid(column=1,row=2)

tap_multiply = Button(cal,text='*',command=lambda:add('*'),height=5,width=10)
tap_multiply.grid(column=2,row=2)

tap_divide = Button(cal,text='/',command=lambda:add('/'),height=5,width=10)
tap_divide.grid(column=3,row=2)

tap_enter = Button(cal,text='=',command=make_ans,height=5,width=10)
tap_enter.grid(column=4,row=2)

tap_ac = Button(cal,text='ac',command=clear,height=5,width=10)
tap_ac.grid(column=5,row=2)
