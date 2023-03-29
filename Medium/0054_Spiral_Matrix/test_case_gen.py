class test_case():
    def gen_test_case(self, row_size:int, col_size:int) -> list:
        k = 1;
        result = []
        for i in range(row_size):
            tmp = []
            for j in range(col_size):
                tmp.append(k)
                k+=1
            result.append(tmp)

        return result



def main():
    with open('case.txt', 'w') as file:
        file.write(str(test_case().gen_test_case(10,10)))

if (__name__ == '__main__'):
    main()
