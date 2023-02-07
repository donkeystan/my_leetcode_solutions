import random
with open('case.txt', 'w') as file:
    string = 'aeiou'
    result = ''
    for i in range(5 * (10**5)):
        result += string[random.randint(0,4)]
    file.write(result)