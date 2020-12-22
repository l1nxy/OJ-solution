class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> v(cost.size()+1,0);

        for(auto i = 0; i <v.size(); i++){
            if(i > 1){
                if(i < cost.size())
                {
                v[i] = std::min(v[i-1]+cost[i],v[i-2]+cost[i]);

                }
                else{
                    v[i] = std::min(v[i-1],v[i-2]);
                }
            }
            else{
                v[i] = cost[i];
            }

        }

        // for(auto v1:v){
        //     cout << v1 << endl;
        // }

        return v[v.size()-1];

    }
};

