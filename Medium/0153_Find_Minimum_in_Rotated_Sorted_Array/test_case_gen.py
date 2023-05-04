import random
with open('case.txt', 'w') as file:
    nums = []
    i = 0
    while (i < 5000):
        randnum = random.randint(-5000, 5000)
        if (randnum not in nums):
            nums.append(randnum)
            i += 1
    file.write( str( sorted( nums ) ) )