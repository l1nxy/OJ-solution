#include <iostream>
#include <string>
#include <map>

using namespace std;


int main()
{
    int n = 0;
    cin >>n;
    while(n--)
    {
    map<char,int> m ={
        {'1',0},
        {'2',0},
        {'3',0},
        {'4',0},
        {'5',0},
        {'6',0},
        {'7',0},
        {'8',0},
        {'9',0}
    };
        int num = 0;
        cin>>num;
        string s;
        s.clear();

        for(int i =1;i<=num;i++)
        {
            s+=to_string(i);
        }
        for(size_t i = 0; i < s.length(); ++i)
        {
            ++m[s[i]];
        }
        for(char s= '0';s <='9'; s++)
        {
            cout<<m[s];
            if(s != '9') cout<<" ";
        }
        cout<<endl;

    }
}

