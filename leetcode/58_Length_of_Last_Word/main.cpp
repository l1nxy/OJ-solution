#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // int lengthOfLastWord(string s) {
    //     int num = std::count(s.begin(),s.end(),' ');
    //     if(num == 0){
    //         return s.length();
    //     }
    //     size_t pos = 0;
    //     string token;
    //     vector<string> vs;
    //     while((pos = s.find(" ")) != string::npos)
    //     {
    //         token = s.substr(0, pos);
    //         if(token != " "&& token.empty() == false)
    //             vs.push_back(token);
    //         s.erase(0, pos + 1);
    //     }
    //     if(s.empty() == false)
    //         vs.push_back(s);
    //     for(auto a:vs)
    //         cout<<a<<endl;
    //     if(vs.empty() == true)
    //         return 0;
    //     else
    //         return vs.rbegin()->length();
    // }
    int lengthOfLastWord(string s){
        int ret = 0;
        int len = s.length();
        while(len != 0 && s[len-1] == ' '){
            len--;
        }
        if(len == 0) return 0;
        for(int i = len-1 ;i >= 0; i--)
        {
            ret++;
            if(s[i-1] ==' ')
                return ret;
        }
        return ret;
    }
};
int main()
{
    Solution s;
    cout<< s.lengthOfLastWord("b")<<endl;
    return 0;
}
