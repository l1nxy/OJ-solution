#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int main()
{
    int n = 0;
    string input;
    cin>> n;
    while(n--)
    {
        bool flag = false;
        cin >> input;
        if(input.empty() || input.length() == 1){
            cout<<input.length()<<endl<<endl;
            continue;
        }
        for(size_t i = 1;i<input.length();++i)
        {
            string sub = input.substr(0,i-0);
            string ret;
            int k = input.length()/sub.length();
            for(int j = 0; j < k; j++)
            {
                ret+=sub;
            }
            if(ret == input)
            {
                cout<< sub.size()<<endl;
                if(n != 0) cout<<endl;
                flag = true;
                break;
            }
        }
        if(flag == false){
             cout << input.size()<<endl;
            if(n != 0) cout<<endl;
        }
    }
}
