Lnum = [1,2,3,4,5,6,7,8,9,10,11,12]
for B01 in Lnum:
    Ls1 = list(Lnum)
    Ls1.remove(B01)
    if B01 != 8:
        continue
    for B02 in Ls1:
        Ls2 = list(Ls1)
        Ls2.remove(B02)
        for B03 in Ls2:
            Ls3 = list(Ls2)
            Ls3.remove(B03)
            if B03 != 11:
                continue
            for B04 in Ls3:
                Ls4 = list(Ls3)
                Ls4.remove(B04)
                if B04 != 6:
                    continue
                for B05 in Ls4:
                    Ls5 = list(Ls4)
                    Ls5.remove(B05)
                    Line1 = B01+B02+B03+B04+B05
                    if Line1 > 26:
                        for B06 in Ls5:
                            Ls6 = list(Ls5)
                            Ls6.remove(B06)
                            for B07 in Ls6:
                                Ls7 = list(Ls6)
                                Ls7.remove(B07)
                                if B07 != 7:
                                    continue
                                for B08 in Ls7:
                                    Ls8 = list(Ls7)
                                    Ls8.remove(B08)
                                    if B08 != 5:
                                        continue
                                    for B09 in Ls8:
                                        Ls9 = list(Ls8)
                                        Ls9.remove(B09)
                                        if Ls9[1] != 9 or Ls9[2] != 10:
                                            continue
                                        Line2 = B05+B06+B07+B08+B09
                                        if Line2 > 26 and Line1 == Line2:
                                            Line3 = B09+Ls9[0]+Ls9[1]+Ls9[2]+B01
                                            if Line3 == Line1:
                                                if B01 == 8 and B03 == 11 and B04 == 6 and B07 == 7 and B08 == 5 and Ls9[1] == 9 and Ls9[2] == 10:
                                                    print(B01,B02,B03,B04,B05,B06,B07,B08,B09,'[',Ls9,']')
