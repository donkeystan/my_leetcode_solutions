import random

mlist = []
for i in range(300):
    mlist.append(random.randint(0,2))

with open('test.txt', 'w') as file:
    file.write(str(mlist))
