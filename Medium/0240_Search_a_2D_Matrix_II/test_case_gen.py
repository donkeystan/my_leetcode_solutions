import random
with open('case.txt', 'w') as file:
    tmp = []
    i = 0
    while (i < 300):
        randnum = random.randint(-10**9, 10**3)
        if (randnum not in tmp):
            tmp.append(randnum)
            i += 1

    tmp.sort()
    print(tmp)
    result = []
    for i in tmp:
        print(i)
        result.append( sorted( [ (i + j*10) for j in range(300) ] ) )
    file.write(str(result))