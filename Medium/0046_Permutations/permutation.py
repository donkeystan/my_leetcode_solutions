def isContinue(var, level):
    for i in range(level+1):
        for j in range(i+1, level+1):
            if (var[i] == var[j]):
                return 1
    return 0

def permutaiton(nums:list, var:list, level:int, nums_size:int):

    if (level == nums_size):
        for i in range(nums_size):
            print(nums[var[i]], end=' ')
        print()
    
        return var

    var[level] = 0
    while (var[level] < nums_size):
        
        if ( isContinue(var, level) ):
            var[level] += 1
            continue

        var = permutaiton(nums, var, level+1, nums_size )
        var[level] += 1
        

var = [0,0,0,0,0,0,0,0,0,0]
nums = [1,2,3]

permutaiton(nums, var, 0, len(nums))



