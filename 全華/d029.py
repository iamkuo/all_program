dat_1 = [int(i) for i in input().split()]
dat_2 = [int(i) for i in input().split()]
len_1 = dat_1[0]
len_2 = dat_2[0]
dat_1 = dat_1[1:]
dat_2 = dat_2[1:]
for i in range(len_1+len_2):
    if dat_1 and dat_2:
        if dat_1[0] < dat_2[0]:
            print(dat_1[0],end = " ")
            dat_1.pop(0)
        elif dat_1[0] > dat_2[0]:
            print(dat_2[0],end = " ")
            dat_2.pop(0)
        else:
            print(dat_1[0],end = " ")
            dat_1.pop(0)
            print(dat_2[0],end = " ")
            dat_2.pop(0)
    elif dat_1 or dat_2:
        if dat_1:
            for i in dat_1:
                print(i,end = " ")
        else:
            for i in dat_2:
                print(i,end = " ")
        break
    else:
        break
