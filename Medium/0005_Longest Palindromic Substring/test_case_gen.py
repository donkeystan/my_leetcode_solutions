import random

with open('case.txt', 'w') as file:
    strM = ""
    m = 97
    for i in range(1000):
        strM += str(chr(m))
        m += 1
        if (m > 122):
            m = 97
    file.write(strM)
