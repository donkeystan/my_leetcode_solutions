import random

with open('case.txt','w') as file:
    for i in range(50000):
        rand_num = random.randint(-50000,50000)
        file.write(str(rand_num)+', ')
