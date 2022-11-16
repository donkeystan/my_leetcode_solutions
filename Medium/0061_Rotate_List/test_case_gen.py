import random

with open('case.txt', 'w') as file:
    file.write( str( [ random.randint(-100, 100) for i in range(500) ] ) )