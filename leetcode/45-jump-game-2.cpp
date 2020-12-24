class Solution {
public:
    int jump(vector<int>& nums) {
        int pre = 0;
        int last = 0;
        int old = 0;
        int step = 0;
        while(last < nums.size()-1){
            old = last;
            for(int i =pre; i <=old; i++){
                last = max(last,i+nums[i]);
            }

            step++;
            pre = old;
        }
        return step;
    }
};
