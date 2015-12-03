/* 2015 1203 l1nxy */
#include <stdio.h>
#define MAX 1000

void dfs(char map[MAX][MAX],int indexi,int indexj);
char map[MAX][MAX];
int flag[MAX][MAX];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int i,j;
    int count=0;
    for(i=0;i<MAX;i++)
        for(j=0;j<MAX;j++)
            flag[i][j]=0;
    for(i=0;i<n;++i){
        scanf("%s",map[i]);
        for(j=0;j<m;++j)
            flag[i][j]=1;
    }

    for(i=0;i<n;++i)
        for(j=0;j<m;++j)
        {
            if(map[i][j]=='W'&&flag[i][j]==1)
            {
                dfs(map,i,j);
                count++;
            }

        }
    printf("%d\n",count);
    return 0;
}

void dfs(char map[MAX][MAX],int indexi,int indexj)
{
    int i,j;
    if(map[indexi][indexj]=='.'){
        flag[indexi][indexj]=0;
        return;
    }
    if(flag[indexi][indexj]==0)
        return;
    flag[indexi][indexj]=0;
    dfs(map,indexi+1,indexj);
    dfs(map,indexi+1,indexj+1);
    dfs(map,indexi,indexj+1);
    dfs(map,indexi-1,indexj);
    dfs(map,indexi-1,indexj+1);
    dfs(map,indexi-1,indexj-1);
    dfs(map,indexi,indexj-1);
    dfs(map,indexi+1,indexj-1);
}
