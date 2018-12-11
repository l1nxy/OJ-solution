#include <iostream>
#include <limits>
using namespace std;
using LL = long long;
int main()
{
    LL n,s;
    cin>>n>>s;
    LL v[n+2];
    LL i = 0;
    LL sum = 0;
    LL min_num = numeric_limits<LL>::max();
    while(i<n){
        cin>>v[i];
        sum += v[i];
        min_num = min_num<v[i]?min_num:v[i];
        i++;
    }
    if(sum < s) cout<<"-1"<<endl;
    else{
        cout<<min(min_num,(sum-s)/n)<<endl;
    }
}
