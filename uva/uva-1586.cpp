#include <iostream>
#include <map>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

int main()
{
    map<char,double> m = {
        {'C',12.01},
        {'H',1.008},
        {'O',16},
        {'N',14.01}
    };

    int n = 0;
    cin>>n;
    while(n--)
    {
        string instr;
        cin>>instr;
        double sum = 0;
        for(size_t i = 0;i<instr.length();)
        {
            if(!isdigit(instr[i]))
            {
                size_t j = i+1;
                string num_str;
                while(isdigit(instr[j])){
                    num_str.push_back(instr[j++]);
                };
                if(num_str.empty()) {
                    sum+= m[instr[i]];
                    i = j;
                    continue;
                }

                int t  = stoi(num_str);
                sum += m[instr[i]]*t;
                i=j;
            }
        }
        cout<<fixed<<setfill('0')<<setprecision(3)<<sum<<endl;
    }
}
