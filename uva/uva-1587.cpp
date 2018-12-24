#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;
#define LOCAL

struct surface{
int a;
int b;
};
bool operator==(const surface &a,const surface &b)
{
    return (a.a == b.a)&&(b.b == a.b);
}
bool operator!=(const surface &a,const surface &b)
    {
        return !(a==b);
    }
bool operator<(const surface &a,const surface &b)
{
    return (a.a < b.a)|| (!(b.a<a.a)&&(a.b<b.b));
}
int main()
{
#ifdef LOCAL
    ifstream filein("data.in");
    ofstream fileout("data.out");
    filein.eof();
#define cin filein
//#define cout fileout
#endif

    int a,b;
    vector<surface> sv;
    while(cin>>a>>b)
    {
        sv.clear();
        surface s{max(a,b),min(a,b)};
        sv.push_back(s);
        int n=5;
        while(n--)
        {
            cin>>a>>b;
            surface s{max(a,b),min(a,b)};
            sv.push_back(s);
        }
    sort(sv.begin(),sv.end());

    for(auto i:sv)
        cout<<i.a<<" "<<i.b<<endl;
    if(sv[0] != sv[1] || sv[2]!=sv[3] || sv[4] != sv[5])
        cout<<"IMPOSSIBLE\n";
    else if( sv[0].b != sv[2].b || sv[2].a != sv[4].a || sv[0].a != sv[5].b)
        cout<<"IMPOSSIBLE\n";
    else
        cout<<"POSSIBLE\n";
    }
}
