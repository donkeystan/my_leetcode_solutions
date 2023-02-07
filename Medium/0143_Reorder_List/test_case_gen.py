import random
with open('case.txt', 'w') as file:
    file.write( str( [ random.randint(1,1000) for i in range(5*(10**4)) ]) )