import random
with open('case.txt', 'w') as file:
    file.write(str([random.randint(0,400) for i in range(100)]))