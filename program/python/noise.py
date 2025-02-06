enter = input().split()
enter[0] = "".join(enter[0].split(enter[1]))
if(enter[0][::-1] == enter[0]):
    print("Yes")
else:
    print("No")
