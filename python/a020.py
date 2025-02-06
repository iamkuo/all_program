code_dict = {"A": 10, "J": 18, "S": 26, "B": 11, "K": 19, "T": 27, "C": 12, "L": 20, "U": 28, "D": 13, "M": 21, "V": 29, "E": 14,"N": 22, "W": 32, "F": 15, "O": 35, "X": 30, "G": 16, "P": 23, "Y": 31, "H": 17, "Q": 24, "Z": 33, "I": 34, "R": 25}
a = [i for i in input()]
a[0] = str(code_dict[a[0]])
ans = (int(a[0][1]) * 9 + int(a[0][0]) + sum([int(a[9-i])*i for i in range(8,0,-1)]) + int(a[9]))%10
if ans: print("fake")
else: print("real")
