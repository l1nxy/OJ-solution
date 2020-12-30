class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size() > 1){
        std::sort(stones.begin(),stones.end());
        auto max1 = stones.back();
        stones.pop_back();
        auto max2 = stones.back();
        stones.pop_back();
         if(max1 != max2){
                auto diff = max1- max2;
                stones.push_back(diff);
              }
        }
        if(stones.empty()){return 0;}
        else{
        return stones.front();

        }
    }
};
