import random


mlist = []
for i in range(100000):
    randnum = random.randint(-1000000000, 1000000000)
    mlist.append(randnum)

mlist.sort()

with open('test.txt', 'w') as file:
    file.write(str(mlist))