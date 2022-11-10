import random
with open('case.txt', 'w') as file:
    mlist = []
    i = 0
    while (i < 100**2):
        randnum = random.randint(-10**4, 10**4)
        if (randnum not in mlist):
            mlist.append(randnum)
            i += 1
    mlist.sort()

    with open('case_for_C.txt', 'w') as file2:
        file2.write(str(mlist))
        
    result = []
    k = 0
    for i in range(100):
        tmp = []
        for j in range(100):
            tmp.append( mlist[k] )
            k += 1
        result.append(tmp)
    file.write(str(result))