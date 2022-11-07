import random

with open( 'case.txt', 'w' ) as file:
    result = [ [ random.randint( -2**31, (2**31)-1 ) for i in range(200) ] for i in range(200) ]
    file.write(str(result))