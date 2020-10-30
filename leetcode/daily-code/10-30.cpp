#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int dfs(vector<vector<int>> &grid,int x,int y,vector<vector<int>> &flag){
        if(y >=grid.size() || y < 0){
            return 1;
        }
        if( x >=grid[0].size() || x < 0){
            return 1;
        }
        if(grid[y][x] == 0){
            return 1;
        }
        if(flag[y][x] == 1){
            return 0;
        }
        flag[y][x] = 1;
        int ret = dfs(grid,x+1,y,flag);
        ret += dfs(grid,x,y+1,flag);
        ret += dfs(grid,x-1,y,flag);
        ret += dfs(grid,x,y-1,flag);
        return ret;


    }
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        if(grid[0].empty()) return 0;
        for(int y = 0; y < grid.size(); y++){
            for(int x =0; x < grid[0].size(); x++)
            {
                if(grid[y][x] == 1){
                    auto flag = vector<vector<int>>(grid.size(),vector<int>(grid[0].size(),0));
                    return dfs(grid,x,y,flag);
                }
            }
        }
        return 0;
    }

};


int main(){

    Solution s;

    vector<vector<int>> grid = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    cout << s.islandPerimeter(grid)<< endl;
}
