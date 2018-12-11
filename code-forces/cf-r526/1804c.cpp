#include <iostream>
#include <string>
using namespace std;
const int M = 1e9+7;

using LL=long long;
int main(){
    string s;
    LL count=0;
    cin>>s;
    string str;
    LL ans = 1;
    for(size_t i=0;i<s.length();)
    {
        if(s[i]!='a' && s[i] != 'b'){i++;continue;}
        if(s[i] == 'b'){ count = 0;i++;continue;}
        if(s[i] == 'a'){
            int j = i;
            for(;;j++)
            {
                if(s[j] == 'b'||j==s.length()){
                break;}
                else if(s[j] == 'a'){
                    count++;
                }
            }
            ans *=(count +1)%M;
            ans %=M;
            i=j;
        }
    }
    cout<<ans-1<<endl;
}
