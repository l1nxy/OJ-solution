//l1nxy 2015 12 02
#include <iostream>

using namespace std;

int main()
{
    int n,m;
    int count;
    int temp;
    cin>>count;

    while(count--){
        int v1=0,v2=0;
        cin>>n>>m;
        while(m--){
            cin>>temp;
            v1=std::max(v1,min(n-temp,temp));
            v2=std::max(v2,max(n-temp,temp));

        }
       cout<<v1<<" "<<v2<<endl;
    }
    return 0;
}
