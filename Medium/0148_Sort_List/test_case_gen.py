import random
with open('case.txt', 'w') as file:
    tmp = [ random.randint(-10**5, 10**5) for i in range(50000)]
    file.write(str(tmp))