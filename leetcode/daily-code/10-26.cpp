class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ret;
        int count[101] = {0};
        for(auto v :nums){
            count[v]++;
        }
        for(int i = 1 ; i < 101; ++i){
            count[i] += count[i-1];
        }
        for(auto v:nums){
            ret.push_back(v?count[v-1]:0);
        }
        return ret;
    }
};
