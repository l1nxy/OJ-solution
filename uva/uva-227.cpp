#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;


bool swap_char(vector<string> &s,int &i,int &j,char cmm)
{
    switch (cmm) {
        case 'A':
            if(i - 1 <0){
                return false;
            }
            swap(s[i][j],s[i-1][j]);
            i -=1;
            break;
        case 'B':
            if(i + 1 == 5){
                return false;
            }
            swap(s[i][j],s[i+1][j]);
            i+=1;
            break;
        case 'L':
            if(j - 1 <0){
                return false;
            }
            swap(s[i][j],s[i][j-1]);
            j-=1;
            break;

        case 'R':
            if(j + 1 ==5){
                return false;
            }
            swap(s[i][j],s[i][j+1]);
            j+=1;
            break;
        default:
            break;
    }
    return true;
}
int main()
{
#ifdef LOCAL
    ifstream filein("data.in");   // 定义一个文件输入流
    ofstream fileout("data.out"); //cout<< --> fileout<<
    filein.eof(); //文件到末尾,返回非零值
#endif
//#define cin filein
//#define cout fileout
    vector<string> v_str;
    string cmm;
    static int count = 1;
    while(true)
    {
        v_str.clear();
        cmm.clear();
        for(size_t i = 0; i < 5 ;++i)
        {
            string s;
            getline(cin,s);
            if(s == "Z")
            {
                return 0;
            }
            v_str.push_back(s);
        }

        char c;
        while((c =getchar()) != '0')
        {
            cmm.push_back(c);
        }
        cin.get();

        int x = 0;
        int y = 0;
        bool flag = false;
        for(size_t i = 0 ;i< v_str.size(); ++i)
        {
            for(size_t j = 0; j< v_str[i].length();++j)
            {
                if (v_str[i][j] == ' ')
                {
                    x = i;
                    y = j;
                    flag = true;
                    break;
                }
            }
            if(flag == true)
                break;
        }

        if(count != 1) cout<<endl;
        bool xxxx = false;
        for(size_t i = 0; i< cmm.length();++i)
        {
            if(swap_char(v_str,x,y,cmm[i]) == false){
                cout<<"Puzzle #"<<count++<<":"<<endl;
            cout<<"This puzzle has no final configuration."<<endl;
            xxxx= true;
            break;}
        }
        if(xxxx==true) continue;
        cout<<"Puzzle #"<<count++<<":"<<endl;
        for(auto &i : v_str)
        {
            for(size_t j = 0; j<5; j++)
            {
                cout<<i[j];
                if(j!=4) cout<<" ";
            }
            cout<<endl;
        }
    }
}

