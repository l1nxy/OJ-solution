class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ret;
        int pos[26];
        for(auto i = 0; i< S.size(); ++i){
            pos[S[i]-'a'] = i;
        }
        int start = 0;
        int end = 0;
        for(auto i= 0; i< S.size(); ++i){
            end = std::max(pos[S[i]-'a'],end);
            if(end == i){
                ret.push_back(end-start+1);
                start = end+1;
                i = end;
            }

        }
        return ret;
    }
};