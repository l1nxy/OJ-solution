#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
#define LOCAL
int find_pos(vector<int> &v,vector<int> &v1,int val1,int val2)
{
    for(auto i = 0; i< v.size(); ++i)
    {
        if(v[i] == val1&& v1[i] == val2){
            return i;
        }
    }
    return -1;
}
int main()
{
#ifdef LOCAL
    ifstream filein("data.in");
    ofstream fileout("data.out");
    filein.eof();
#endif
    int n,m;
    int count = 1;
    while(cin >>n >> m )
    {
        vector<int> remainder;
        vector<int> dec;
        int  x =  n / m;
        int y =n % m;
        while( y != 0 ){
            int d_pos = find_pos(remainder,dec,y,(y*10)/m);
            if(d_pos != -1)
            {
                cout<< n<< "/"<<m << " = ";
                cout << x << ".";
                int size = dec.size()< 50? dec.size():50;
                for(auto i = 0; i < size; ++i)
                {
                    if(i == d_pos)
                    {
                        cout<<"(";
                    }
                    cout<<dec[i];
                }
                if(dec.size() > 50)cout<<"...";
                cout<<")\n";
                cout<<"   "<<dec.size()-d_pos<<" = number of digits in repeating cycle\n\n";
                dec.clear();
                break;
            }
            remainder.push_back(y);
            y *= 10;
            int d = y / m;
            dec.push_back(d);
            y -= d*m;
        }
        if(!dec.empty() )
        {
            cout<< n<< "/"<<m << " = ";
            cout << x << ".";
            for(auto i = 0; i< dec.size(); ++i)
            {
                cout<< dec[i];
            }
            cout<<"(0)"<<endl;
            cout<<"   "<<1<<" = number of digits in repeating cycle\n\n";
        }
        else if(dec.empty() && y == 0)
        {
            cout<< n<< "/"<<m << " = ";
            cout << x << ".";
            cout<<"(0)"<<endl;
            cout<<"   "<<1<<" = number of digits in repeating cycle\n\n";
        }

        count++;
    }
}
