# Constraints:
# nums1.length == m
# nums2.length == n
# 0 <= m <= 1000
# 0 <= n <= 1000
# 1 <= m + n <= 2000
# -10^6 <= nums1[i], nums2[i] <= 10^6


import random

xlist = []
ylist = []
for i in range(1000):
    xlist.append(random.randint(-1000000, 1000000))
    ylist.append(random.randint(-1000000, 1000000))

xlist.sort()
ylist.sort()

with open('x_case.txt', 'w') as file:
    file.write(str(xlist))

with open('y_case.txt', 'w') as file:
    file.write(str(ylist))