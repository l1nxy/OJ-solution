#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
//#define LOCAL
using namespace std;

int check(vector<int> &v,string &s,char c)
{
    for(auto i = 0;i< s.size(); ++i)
    {
        if(s[i] == c)
        {
            if(v.empty()){
                return i;
            }
            else if(i > *(v.end()-1))
                return i;
        }
    }
    return -1;
}
int main()
{
#ifdef LOCAL
    ifstream filein("data.in");
    ofstream fileout("data.out");
    filein.eof();
#define cin filein
#endif

    string str1,str2;

    vector<int> v;
    while(cin >>str1 >> str2)
    {
        v.clear();
        bool flag = false;
        for(auto i = 0;i<str1.size();++i)
        {
            int ret = check(v, str2,str1[i]);
            if( ret == -1)
            {
                cout<<"No"<<endl;
                flag = true;
                break;
            }
            else{
                v.push_back(ret);
            }
        }
        if(flag == true) continue;
        cout<<"Yes"<<endl;
    }
    return 0;
}

