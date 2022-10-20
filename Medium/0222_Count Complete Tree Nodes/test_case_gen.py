with open('case.txt', 'w') as file:
    mlist = []

    for i in range(5* (10**4) ):
        mlist.append(i)
    
    file.write(str(mlist))


