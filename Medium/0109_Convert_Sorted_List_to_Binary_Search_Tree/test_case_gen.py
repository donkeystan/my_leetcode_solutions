import random
with open('case.txt', 'w') as file:
    result = []
    while (len(result) < 20000 ):
        randnum = random.randint(-10**5, 10**5)
        if ( randnum not in result ):
            result.append(randnum)
    file.write(str(sorted(result)))