#include <bits/stdc++.h>
using namespace std;


class Solution {

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> v;
        map<string, int> m;
        int index = 0;
        for(auto i : strs)
        {
            string str = i;
            sort(str.begin(),str.end());
            if(m.count(str) == 0)
            {
                vector<string> strv;
                strv.push_back(i);
                v.push_back(strv);
                m[str] = index++;
            }
            else
            {
                v[m[str]].push_back(i);
            }
        }
        return v;
    }
};


int main(int argc, char *argv[])
{

    return 0;
}
