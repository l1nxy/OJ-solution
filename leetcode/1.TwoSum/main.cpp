#include <iostream>
#include <vector>
#include <map>
using namespace std;


vector<int> TowSum(vector<int> &nums,int target)
{
    vector<int> temp;
    map<int,int> m;
    for (size_t i=0;i<nums.size();i++){
        m[nums[i]]=i;
    }
    for(size_t i=0;i<nums.size();i++){
        int t=target-nums[i];
        if(m.find(t)!=m.end()&&m[t]!=m[nums[i]]){
        temp.push_back(i+1);
        temp.push_back(m[t]+1);
        return temp;
        }
    }
}
int main(int argc, char *argv[])

{
    vector<int> v={3,2,4};
    vector<int> s=TowSum(v,6);
    for(auto &a:s)
        cout<<a<<endl;
    return 0;
}
