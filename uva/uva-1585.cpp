#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin>> n;

    while(n--)
    {
        string str;
        int count = 0;
        int sum = 0;
        cin>>str;
        for(size_t i = 0;i< str.length();++i)
        {
            if(str[i] == 'X'){
                count=0;
                continue;
            }
            else{
                count++;
            }
            sum += count;
        }
        cout<<sum<<endl;
    }
}
