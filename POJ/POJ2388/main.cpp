#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N=0;
    int temp;
    vector<int> v1;
    cin>>N;
    int n=N;
    while(N--){
        cin>>temp;
        v1.push_back(temp);

    }
    std::sort(v1.begin(),v1.end());
    cout<<v1[n/2]<<endl;

    return 0;
}
