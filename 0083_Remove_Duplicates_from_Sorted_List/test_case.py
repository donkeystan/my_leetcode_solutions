import random

with open("test.txt","w") as file:
    mylist = []

    for i in range(300):
        rand = random.randint(-100,100)
        mylist.append(rand)

    for i in range(len(mylist)):
        for j in range(i+1, len(mylist)):
            if (mylist[j]<=mylist[i]):
                mylist[j] ^= mylist[i]
                mylist[i] ^= mylist[j]
                mylist[j] ^= mylist[i]

    mylist = list(map(str, mylist))        
    for sr in mylist:
        sr += ', '
        file.write(sr)