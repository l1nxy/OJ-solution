#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string a,b;
    while(cin>>a>>b)
    {
        bool flag = false;
        int t1[26] = {0};
        int t2[26] = {0};
        for(auto i:a)
            t1[i-'A']++;
        for(auto i:b)
            t2[i-'A']++;
        sort(begin(t1),end(t1));
        sort(begin(t2),end(t2));
        for(auto i = 0; i<26;i++)
        {
            if(t1[i] != t2[i])
            {
                cout<<"NO"<<endl;
                flag =true;
            }
            if(flag)
                break;
        }
        if(flag == false)
            cout<<"YES\n";
    }
}
