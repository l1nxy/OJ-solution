#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool Find(int target, vector<vector<int> > array){
        int x = array[0].size()-1;
        int y = 0;
        while(x >= 0 && y < array.size())
        {
            if(array[y][x] < target)
            {
                y++;
                continue;
            }
            if(array[y][x] > target)
            {
                x--;
                continue;
            }
            if(array[y][x] == target)
                return true;
        }
        return false;
    }
};



int main(){
    //vector<vector<int>> v = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> v;
    Solution s;
    cout << s.Find(0,v) << endl;
}
