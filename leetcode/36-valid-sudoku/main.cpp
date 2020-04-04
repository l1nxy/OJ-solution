#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (size_t i = 0; i < 9; ++i)
        {
            int record[10] = {0};
            memset(record, 0, 10 * sizeof(int));
            for (size_t j = 0; j < 9; ++j)
            {
                if (board[i][j] == '.')
                    continue;
                // cout <<board[i][j] << endl;
                if (record[board[i][j] - '0'] == 1)
                    return false;
                else
                {
                    record[board[i][j] - '0'] = 1;
                }
            }
        }

        for (size_t i = 0; i < 9; ++i)
        {

            int record[10] = {0};
            memset(record, 0, 10 * sizeof(int));
            for (size_t j = 0; j < 9; ++j)
            {
                if (board[j][i] == '.')
                    continue;
                if (record[board[j][i] - '0'] == 1)
                    return false;
                else
                {
                    record[board[j][i] - '0'] = 1;
                }
            }
        }

        for (size_t k = 0; k < 9; k++)
        {
            int record[10] = {0};
            memset(record, 0, 10 * sizeof(int));
            for (size_t i = 0; i < 3; ++i)
            {
                for (size_t j = 0; j < 3; ++j)
                {
                    //cout  << board[i + k / 3][j + (k % 3)*3] << endl;
                    if (board[i + (k / 3)*3][j + (k % 3)*3] == '.')
                        continue;
                    if (record[board[i + (k / 3)*3][j + (k % 3)*3] - '0'] == 1)
                    {
                        cout << i + (k / 3)*3 << " " << j + (k % 3)*3 << endl;
                        return false;
                    }
                    else
                    {
                        record[board[i + (k / 3)*3][j + (k % 3)*3] - '0'] = 1;
                    }
                }
            }
        }
        return true;
    }
};
int main()
{
    Solution s;
    vector<vector<char>> m = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    cout << s.isValidSudoku(m) << endl;
    return 0;
}
