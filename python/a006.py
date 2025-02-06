from math import sqrt
a,b,c = [int(i) for i in input().split()]
de = b**2-4*a*c
if de > 0:
    print("Two different roots x1="+ str(int((b*-1 + sqrt(de))//(2*a))) + " , x2=" + str(int((b*-1 - sqrt(de))//(2*a))))
elif de == 0:
    print("Two same roots x=" + str(int(b*-1//(2*a))))
else:
    print("No real root")
