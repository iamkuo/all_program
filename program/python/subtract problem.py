Lnum = [1,2,3,4,5,6,7,8,9]
for i in Lnum:
    Ls1 = list(Lnum)
    Ls1.remove(i)
    for j in Ls1:
        Ls2 = list(Ls1)
        Ls2.remove(j)
        for k in Ls2:
            Ls3 = list(Ls2)
            Ls3.remove(k)
            for m in Ls3:
                nn = i*1000+j*100+k*10+m
                mm = 66666+nn
                Ls4 = list(Ls3)
                Ls4.remove(m)
                for p in range(5):
                    dd = mm%10
                    mm = mm//10
                    if dd in Ls4:
                        Ls4.remove(dd)
                    else:
                        break
                if len(Ls4) == 0:
                    print(66666+nn,nn,i,j,k,m)
