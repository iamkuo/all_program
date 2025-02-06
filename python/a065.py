dat = [ord(i) for i in input()]
print("".join([str(abs(dat[i]-dat[i-1])) for i in range(1,len(dat))]))
