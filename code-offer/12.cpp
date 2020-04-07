#include <bits/stdc++.h>

using namespace std;

class Solution
{
    bool dfs(vector<vector<char>> &board, string &word, int x, int y, int depth)
    {
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size())
            return false;
        if (word[depth] != board[x][y])
            return false;
        if(depth == word.size()-1) return true;
        char temp = board[x][y];
        board[x][y] = '#';
        bool ret = dfs(board, word, x + 1, y, depth + 1) || dfs(board, word, x - 1, y, depth + 1) ||
                   dfs(board, word, x, y + 1, depth + 1) || dfs(board, word, x, y - 1, depth + 1);
        board[x][y] = temp;
        return ret;
    }

  public:
    bool exist(vector<vector<char>> &board, string word)
    {
        for (size_t i = 0; i < board.size(); ++i)
        {
            for (size_t j = 0; j < board[0].size(); j++)
            {
                if(dfs(board,word,i,j,0) == true)
                    return true;
            }
        }
        return false;
    }
};
int main(int argc, char *argv[])
{

    return 0;
}
