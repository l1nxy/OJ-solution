#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n,m;
    vector<string> str;
    static int count = 1;
    while(true)
    {
        str.clear();
        cin>>n;
        if(n == 0)
        {
            return 0;
        }
        cin>>m;
        cin.get();
        vector<string> across;
        vector<string> down;
        vector<int> ac_index;
        vector<int> donw_index;
        for(int i = 0;i < n ; ++i)
        {
            string temp;
            getline(cin,temp);
            str.push_back(temp);
        }

        int index_array[n][m];
        int temp_count = 1;
        for(int i = 0; i< n; ++i)
        {
            for(int j = 0;j<m;++j)
            {
                if((i == 0 || j == 0|| str[i][j-1] == '*' || str[i-1][j] == '*')&& str[i][j]!='*') {
                    index_array[i][j] = temp_count++;
                }
                else{
                    index_array[i][j]= 0;
                }
            }
        }

        for(int i = 0; i < n ;++i)
        {
            string temp;
            for(int j = 0; j< m; ++j)
            {
                if(str[i][j] == '*')
                {
                    if(temp.empty()) continue;
                    ac_index.push_back(index_array[i][j-temp.size()]);
                    across.push_back(temp);
                    temp.clear();
                }
                else{
                    temp.push_back(str[i][j]);
                }
            }
            if(!temp.empty()){
                ac_index.push_back(index_array[i][m-temp.length()]);
                across.push_back(temp);
                temp.clear();
            }
        }


        for(size_t i = 0; i < n ;++i)
        {
            for(size_t j = 0; j< m; ++j)
            {
                if(str[i][j] != '*')
                {
                    string temp;
                    for(size_t k = i;k<n;++k)
                    {
                        if(str[k][j] != '*'){
                            temp.push_back(str[k][j]);
                            str[k][j] = '*';
                        }
                        else{
                        break;}
                    }
                    down.push_back(temp);
                    donw_index.push_back(index_array[i][j]);
                }
            }
        }

        if(count != 1) cout<<endl;

        cout << "puzzle #" << count++ << ":" <<endl;
        cout << "Across"<<endl;
        for(size_t i = 0 ; i< across.size();++i)
        {
            cout.setf(ios::right);
            cout.width(3);
            cout.fill(' ');
            cout<<ac_index[i];
            cout<<"."<<across[i]<<endl;
        }
        cout << "Down"<<endl;
        for(size_t i = 0 ; i< down.size();++i)
        {
            cout.setf(ios::right);
            cout.width(3);
            cout.fill(' ');
            cout<<donw_index[i];
            cout<<"."<<down[i]<<endl;
        }

    }
    return 0;
}
