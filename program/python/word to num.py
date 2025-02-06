while True:
    try:
        word_tmp = input()
        word = []
        for i in range(len(word_tmp)):
            word.append(word_tmp[i])
        match = {'A':1,'B':2,'C':3,'D':4,'E':5,'F':6,'G':7,'H':8,'I':9,'J':10,'K':11,'L':12,
                 'M':13,'N':14,'O':15,'P':16,'Q':17,'R':18,'S':19,'T':20,'U':21,'V':22,'W':23,
                 'X':24,'Y':25,'Z':26}
        ans = []
        for i in range(1,7):
            tmp = word[i]
            first = match[tmp]
            second = match[word[i-1]]
            if first > second:
                ans.append(first-second)
            else:
                ans.append(second-first)
        for i in range(len(ans)):
            ans[i] = str(ans[i])
        print(''.join(ans))
    except:
        break
d
