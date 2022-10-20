with open('test_case.txt','w') as file:
    list = []
    for i in range(200000-2):
        strs='1, '
        file.write(strs)
        list += [1]
    print(list)