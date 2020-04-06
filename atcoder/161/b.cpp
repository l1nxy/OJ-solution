#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(int argc, char *argv[])
{
    int n,m;
    cin >> n >>m ;
    vector<int> v;
    LL total = 0;
    while(n--)
    {
        int x;
        cin >> x;
        v.push_back(x);
        total += x;
    }

    int cnt = 0;
    for(auto i : v)
    {
        if(i * 4 * m >= total) cnt++;
    }
    if(cnt < m)
        cout<<"No"<<endl;
    else
        cout<<"Yes"<<endl;
    return 0;
}
