#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    void helper(vector<vector<char>> &grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid[0].size() || j >= grid.size())
        {
            return;
        }
        if (grid[j][i] == '0')
            return;
        else
            grid[j][i] = '0';
        helper(grid, i + 1, j);
        helper(grid, i - 1,j);
        helper(grid,i,j+1);
        helper(grid, i,j-1);
    }

  public:
    int numIslands(vector<vector<char>> &grid)
    {
        if(grid.empty() == true)
            return 0;
        int ret= 0;
        for(int i =0;i < grid[0].size(); ++i)
            for(int j = 0; j <grid.size(); ++j)
            {
                if(grid[j][i] == '1')
                {
                    helper(grid,i,j);
                    ret++;
                }
            }
        return ret;
    }
};
int main()
{
}
