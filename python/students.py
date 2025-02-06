while True:
    students = list(range(1,int(input())+1))
    weekend = [int(i) for i in input().split()]
    for i in range(3):
        students.pop(students.index(weekend[i]))
    for i in reversed(range(len(students))):
        print('No.',students[i])
