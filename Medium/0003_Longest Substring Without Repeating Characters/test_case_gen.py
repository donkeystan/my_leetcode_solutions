import random

string = ""
for i in range(5*(10**4)):
    string +=  chr( random.randint(65,90))

# print(string)

with open('case.txt', 'w', encoding='UTF-8') as file:
    file.write( str(string) )
