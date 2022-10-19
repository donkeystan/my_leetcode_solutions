import random as rdn

with open('case.txt', 'w') as file:

    list = []
    for i in range(5000):
        list.append(rdn.randint(-10**4, 10**4))
    list.sort()
    file.write(str(list))