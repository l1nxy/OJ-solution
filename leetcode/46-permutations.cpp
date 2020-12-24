class Solution {
    void trace(vector<int> &source,vector<int>& trace_nums){
        if(trace_nums.size() == source.size()){
            ret.push_back(trace_nums);
            return;
        }
        for(auto n : source){
            if(std::find(trace_nums.begin(),trace_nums.end(),n) != trace_nums.end()){
                continue;
            }
            trace_nums.push_back(n);
            trace(source,trace_nums);
            trace_nums.pop_back();
        }
    }
    vector<vector<int>> ret;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> t;
        trace(nums,t);
        return ret;
    }
};

class Solution {
    void solution(vector<int> &nums,int index)
    {
        if(index == nums.size())
        {
            ret.push_back(nums);
            return;
        }
        for(auto i = index; i < nums.size(); i++){
            swap(nums[i],nums[index]);
            solution(nums,index+1);
            swap(nums[i],nums[index]);
        }
    }

    vector<vector<int>> ret;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        solution(nums,0);
        return ret;
    }
};
