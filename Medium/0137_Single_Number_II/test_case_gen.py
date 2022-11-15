import random
with open('case.txt', 'w') as file:
    result = []
    for i in range(10**4):
        randnum = random.randint(-2**31, ((2**31)-1) )
        for i in range(3):
            result.append(randnum)
    file.write(str(result))