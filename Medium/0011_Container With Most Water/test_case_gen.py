import random

with open('case.txt', 'w') as file:
    tmp = [ random.randint(0, 10**4) for i in range(10**5)]
    file.write(str(tmp))