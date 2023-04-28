def get_prime(k:int) -> list:
    prime_list = [1, 2, 3]
    for num in range(4, k+1):
        is_prime = 1
        for i in range(2, num):
            if (num % i == 0):
                is_prime = 0
                break
        if (is_prime == 1):
            prime_list.append(num)
    return prime_list

def main():
    k = 10000
    prime_list = get_prime(k)
    with open('case.txt', 'w') as file:
        file.write(str(prime_list[:1000])+'\n')
        file.write(str(1000*999//2))

if (__name__ == '__main__'):
    main()