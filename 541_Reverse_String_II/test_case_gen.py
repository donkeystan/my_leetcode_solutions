import random

string = ""
for i in range(10000):
    string += chr( random.randint(97,122))

with open('case.txt', 'w') as file:
    file.write(string)
