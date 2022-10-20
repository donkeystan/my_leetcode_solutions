import random

with open('case.txt','w') as file:
    for i in range(-9999,10000,2):
        file.write(str(i)+', ')