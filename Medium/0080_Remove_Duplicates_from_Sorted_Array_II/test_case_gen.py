import random

with open('case.txt', 'w') as file:
    file.write(str(sorted([random.randint(-10**4, 10**4) for i in range(3*(10**4))])))