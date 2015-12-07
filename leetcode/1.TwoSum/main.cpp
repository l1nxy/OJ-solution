#include <iostream>
#include <vector>

using namespace std;


vector<int> TowSum(vector<int> &nums,int target)
{
    vector<int> temp;
    for (size_t i = 0; i < nums.size(); i++) {
        for( size_t j=i+1;j<nums.size();j++)
            if(nums[i]+nums[j]==target){
                temp.push_back(i);
                temp.push_back(j);
                return temp;
            }

    }
}
int main(int argc, char *argv[])

{
    vector<int> v={2,7,11,19};
    vector<int> s=TowSum(v,9);
    for(auto &a:s)
        cout<<a<<endl;
    return 0;
}
