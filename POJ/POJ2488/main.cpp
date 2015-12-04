#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

int a[100];
int b[100];
int t1=0;
int flag=0;
int sizex,sizey;
int indexi[8]={-1,1,-2,2,-2,2,-1,1};
int indexj[8]={-2,-2,-1,-1,1,1,2,2};
void dfs(bool (&Map)[100][100],int x,int y,int step){
    if(x<0||y<0||x>=sizex||y>=sizey)
        return ;
    if(Map[x][y]==false)
        return ;
    if(flag==1) return;
    if(step==t1) flag=1;
    a[step]=x;
    b[step]=y;
    for (int i = 0; i < 8; ++i) {
        Map[x][y]=false;
        dfs(Map,x+indexi[i],y+indexj[i],step+1);
        Map[x][y]=true;
    }
}

int main()
{
    int n;
    cin>>n;
    int temp=n;
    int count=1;
    bool map[100][100]={false};
    while(temp--){
        flag=0;
        int x,y;
        cin>>x>>y;
        t1=x*y;
        sizex=x;
        sizey=y;
        for (int i = 0; i < x; ++i) {
            for(int j=0;j<y;++j)
                map[i][j]=true;

        }
        dfs(map,0,0,1);
        cout<<"Scenario #"<<count++<<":"<<endl;
        if(flag==1){
        for (int i = 1; i <= t1; ++i) {
            cout<<char(b[i]+'A')<<a[i]+1;
        }
        cout<<endl;
        }
        else
            cout<<"impossible"<<endl;
        cout<<endl;
    }
    return 0;
}
