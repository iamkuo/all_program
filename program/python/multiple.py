'''
def multiple(x):
    if x == 1:
        return 3
    return multiple(x-1)+x*3
x = int(input())
print(multiple(x))
print(sum([i*3 for i in range(x+1)]))
'''

def numbers(x):
    print(x)
    if x == 2:
        return 3
    elif x == 1:
        return 1
    else:
        return numbers(x-1)+numbers(x-2)
x = int(input())
print(numbers(x))
