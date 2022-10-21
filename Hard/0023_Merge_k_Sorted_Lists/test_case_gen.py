# k == lists.length
# 0 <= k <= 10^4
# 0 <= lists[i].length <= 500
# -10^4 <= lists[i][j] <= 10^4


import random

with open('case.txt', 'w') as file:
    lists = []
    for i in range(100):
        tmp = [ random.randint(-10**4, 10**4) for i in range(100) ]
        tmp.sort()
        file.write(str(tmp))