#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;


vector<char> check(vector<string> &v, int j){
    int count = 0;
    vector<char> ret;
    map<char,int> m ={
        {'A',0},
        {'T',0},
        {'G',0},
        {'C',0}
    };

    for(auto i = 0 ; i< v.size(); ++i)
    {
        m[v[i][j]]++;
    }
    for(auto i:m)
    {
        if(i.second > count)
        {
            count = i.second;
        }
    }
    for(auto i:m)
    {
        if(i.second == count)
                ret.push_back(i.first);
    }
    return ret;

}

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        vector<string> ret;
        int min = 0;
        int x,y;
        cin >> x >> y;
        int t = x;
        vector<string> v;
        while(t -- )
        {
            string temp;
            cin >>  temp ;
            v.push_back(temp);
        }

        for(auto i = 0; i< y; i++)
        {
            auto v1 = check(v,i);
            sort(v1.begin(),v1.end());
            if( i == 0)
            {
                    string s(1,v1[0]);
                    ret.push_back(s);
            }
            else
            {
                for(auto &i:ret)
                {
                    i+=v1[0];
                }
            }
        }
        for(auto j = 0; j < x; ++j)
        for(auto i = 0; i < y; ++i)
        {
            if(ret[0][i] != v[j][i])
                min++;
        }

        cout<<ret[0]<<endl;
        cout<<min<<endl;
    }
}
