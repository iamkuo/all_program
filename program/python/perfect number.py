num = int(input("請輸入一個整數: "))
for i in range(2, num):
  if num % i == 0:
    power = 0
    print(i, end="^")
    while num % i == 0:
      power += 1
      num /= i
    print(power, end=' ')
