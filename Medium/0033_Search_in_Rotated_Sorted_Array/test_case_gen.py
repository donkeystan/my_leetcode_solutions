import random

with open('case.txt', 'w') as file:
    list = []
    for i in range(5000):
        list.append(i)
    
    list.sort()

    file.write(str(list))
