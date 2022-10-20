with open('case.txr', 'w') as file:
    mlist = []
    for i in range(10**5):
        mlist.append(i)
    
    mlist.sort()

    file.write(str(mlist))
    