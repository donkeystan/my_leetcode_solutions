import random
with open('case.txt', 'w') as file:
    file.write(str([random.randint(0, 10**5) for i in range(1,10**4)]))