import random
with open('case.txt', 'w') as file:
    file.write(str([random.randint(1, 10**4) for i in range(10**5)]))