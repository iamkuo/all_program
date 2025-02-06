words = [' ! he said ',' as he jumped into his convertible ',' and drove off with his ',' wife.']
hint = ['exclamation','adverb','noun','adjective']
enter = []
for i in range(4):
    enter.append(input('Please enter a '+hint[i]))
print(enter[0]+words[0]+enter[1]+words[1]+enter[2]+words[2]+enter[3]+words[3])
