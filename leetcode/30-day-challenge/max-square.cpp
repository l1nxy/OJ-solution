#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        vector<vector<int>> v(matrix.size()+1,vector<int>(matrix[0].size()+1,0));
        int max_value = 0;
        for(auto i = 1; i <= matrix.size(); ++i){
            for(auto j = 1; j <= matrix[0].size(); j++){
                if(matrix[i-1][j-1] == '1'){
                    v[i][j] = std::min(std::min(v[i-1][j],v[i][j-1]),v[i-1][j-1]) + 1;
                    max_value = std::max(max_value,v[i][j]);
                }
            }
        }
        return max_value * max_value;
    }
};
int main(){

}
