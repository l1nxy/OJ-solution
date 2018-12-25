#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){

    int n;
    string a,b;
    while(cin >> n)
    {
        if(n == -1)
            return 0;
        cin >> a>>b;

        int error_count = 0;
        int guess_count = 0;
        for(auto i:b)
        {
            auto iter = find(a.begin(),a.end(),i);
            if(iter == a.end())
            {
                error_count++;
            }
            else{
                for(auto &j:a)
                {
                    if(i == j)
                    {
                        guess_count++;
                        j = ' ';
                    }
                }
            }
            if(error_count == 7)
            {
                cout<<"Round "<<n<<endl;
                cout<<"You lose."<<endl;
                break;
            }
            if(guess_count == a.size()){
                cout<<"Round "<<n<<endl;
                cout<<"You win."<<endl;
                break;
            }

        }

        if(guess_count< a.size() && error_count < 7)
        {
            cout<<"Round "<<n<<endl;
            cout<<"You chickened out."<<endl;
        }
    }
}
