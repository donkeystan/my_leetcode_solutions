import random

with open('case.txt', 'w') as file:

    matrix = []
    for i in range(20):
        tmp = []
        for j in range(20):
            tmp.append(random.randint(-1000, 1000))
        matrix.append(tmp)

    file.write(str( matrix ))