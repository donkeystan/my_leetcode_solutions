import random
with open('case.txt', 'w') as file:
    file.write( str( [ random.randint(-5000, 5000) for i in range(5000) ] ) )