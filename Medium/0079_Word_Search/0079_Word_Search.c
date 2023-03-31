#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define ROW 3
#define COL 4

void print_array(char *nums, int nums_size);
void print_2d_array(char **matrix, int row_Size, int *col_sizes);
void print_nums(int *nums, int nums_size);
void print_trackboard(int **matrix, int row_Size, int col_size);

void clean_board(int **board, int row_size, int col_size)
{
    int i, j;
    for (i=0; i<row_size; i++)
    {
        for (j=0; j<col_size; j++)
        {
            board[i][j] = 0;
        }
    }
}

void rewind_board(int **board, int rewind_i, int rewind_j)
{
    board[rewind_i][rewind_j] = 0;
}

int search(char **board, int i, int j, int level, char *word, int word_length, int row_size, int col_size, int **track_board, int defualt_i, int default_j)
{
    // base condition, if the passed in level matches the word's last element, the word is FOUND, and return TRUE
    if (level == word_length-1)
    {
        clean_board(track_board, row_size, col_size);
        return 1;
    }

    int rc = 0;

    // Search Up
    if (i-1 >= 0 && board[i-1][j] == word[level+1] && track_board[i-1][j] != 1)
    {
        // when next letter of the word is found matching the element 1 column above current indext, update track board with visited i j column, then do the search.
        track_board[i-1][j] = 1;
        rc = search(board, i-1, j, level+1, word, word_length, row_size, col_size, track_board, defualt_i, default_j);

        // if any successful search is done, directly return the result without proceeding with further recursive search.
        if (rc == 1)
        {
            return 1;
        }        
    }

    // Search Down
    if (i+1 < row_size && board[i+1][j] == word[level+1] && track_board[i+1][j] != 1)
    {
        track_board[i+1][j] = 1;
        rc = search(board, i+1, j, level+1, word, word_length, row_size, col_size, track_board, defualt_i, default_j);
        if (rc == 1)
        {
            return 1;
        }
    }

    // Search Left
    if (j-1 >= 0 && board[i][j-1] == word[level+1] && track_board[i][j-1] != 1)
    {
        track_board[i][j-1] = 1;
        rc = search(board, i, j-1, level+1, word, word_length, row_size, col_size, track_board, defualt_i, default_j);
        if (rc == 1)
        {
            return 1;
        }
    }

    // Search Right
    if (j+1 < col_size && board[i][j+1] == word[level+1] && track_board[i][j+1] != 1)
    {
        track_board[i][j+1] = 1;
        rc = search(board, i, j+1, level+1, word, word_length, row_size, col_size, track_board, defualt_i, default_j);
        if (rc == 1)
        {
            return 1;
        }
    }

    // if search fails, rewind the visited place to previous state
    rewind_board(track_board, i, j);
    return 0;
}

bool exist(char** board, int boardSize, int* boardColSize, char * word)
{
    int word_length = strlen(word);
    int i, j;
    int rc = 0;

    // 0. return if word is longer thatn board m x n
    if (word_length > (boardSize * boardColSize[0]))
    {
        return 0;
    }

    // 1. prepare an empty board in equal size to the board
    int **track_board = (int **)malloc(sizeof(int *) * boardSize);
    for (i=0; i<boardSize; i++)
    {
        track_board[i] = (int *)malloc(sizeof(int) * boardColSize[i]);
        for (j=0; j<boardColSize[i]; j++)
        {
            track_board[i][j] = 0;
        }
    }

    // 2. loop through the board to start search
    for (i=0; i<boardSize; i++)
    {
        for (j=0; j<boardColSize[i]; j++)
        {
            // 2.1 if any letter found matches the first letter of the word, proceed with the search
            if (board[i][j] == word[0])
            {
                // 2.1.1  when first letter of the word is found, return true if the word length is only 1
                if (word_length == 1)
                {
                    return 1;
                }

                // 2.1.2 else do the search. put 1 in the current i and j index of the trackboard
                track_board[i][j] = 1;

                // 3. start the search from index 1, j
                rc = search(board, i, j, 0, word, word_length, boardSize, boardColSize[i], track_board, i, j);
            }

            if (rc  == 1)
            {
                return 1;
            }
        }
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    int temp[ROW][COL] = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    // int temp[ROW][COL] = {{'A','B','C','E'},{'B','F','C','S'},{'A','D','E','E'}};
    // int temp[ROW][COL] = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    // int temp[ROW][COL] =  {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    // int temp[ROW][COL] = {{'a','a','a','a'},{'a','a','a','a'},{'a','a','a','a'}};
    // int temp[ROW][COL] = {{'a', 'a', 'a'}, {'a','a','a'}};
    //  int temp[ROW][COL] = {{'A','B','C','D'},{'B','E','C','D'},{'F','D','F','E'}};
    // int temp[ROW][COL] = {{'a','a','b','a','a','b'},{'a','a','b','b','b','a'},{'a','a','a','a','b','a'},{'b','a','b','b','a','b'},{'a','b','b','a','b','a'},{'b','a','a','a','a','b'}};
    // char *word = "aaaaaaa";
    char *word = "ABCCED";
    // char *word = "ABFCES";
    // char *word = "SEE";
    // char *word = "ABCB";
    // char *word = "ABCCEE";
    // char *word = "AA";
    // char *word = "aaaaaaaaaaaaa";
    // char *word = "aaaaaaaaaaaa";
    // char *word = "ABF";
    // char *word = "bbbaabbbbbab";

    int boardSize = ROW;
    int *boardColSize = (int *)malloc(sizeof(int) * boardSize);
    int i, j;
    for (i=0; i<boardSize; i++)
    {
        boardColSize[i] = COL;
    }

    char **board = (char **)malloc(sizeof(char *) * boardSize);

    for (i=0; i<ROW; i++)
    {
        board[i] = (char *)malloc(sizeof(char) * COL);
        for (j=0; j<COL; j++)
        {
            board[i][j] = temp[i][j];
        }
    }
    printf("RC --> %d\n", exist(board, boardSize, boardColSize, word));
    return EXIT_SUCCESS;
}

void print_nums(int *nums, int nums_size)
{
    int i;
    printf("[ ");
    for (i=0; i<nums_size; i++)
    {
        printf("%d", nums[i]);
        if (i < nums_size-1)
        {
            printf(", ");
        }
    }
    printf(" ]\n");
}

void print_trackboard(int **matrix, int row_Size, int col_size)
{
    int i;
    printf("< -- Track Board Status -->\n");
    for (i=0; i<row_Size; i++)
    {
        print_nums(matrix[i], col_size);
    }
    printf("-----------End-------------\n\n");
}

void print_array(char *nums, int nums_size)
{
    int i;
    printf("[ ");
    for (i=0; i<nums_size; i++)
    {
        printf("%c", nums[i]);
        if (i < nums_size-1)
        {
            printf(", ");
        }
    }
    printf(" ]\n");
}

void print_2d_array(char **matrix, int row_Size, int *col_sizes)
{
    int i;
    printf("[\n");
    for (i=0; i<row_Size; i++)
    {
        print_array(matrix[i], col_sizes[i]);
    }
    printf("]\n");
}

/*

79. Word Search
Medium
13K
528
Companies
Given an m x n grid of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells,
where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.


Example 1:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false

Constraints:
m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15

board and word consists of only lowercase and uppercase English letters.
 
Follow up: Could you use search pruning to make your solution faster with a larger board?


*/