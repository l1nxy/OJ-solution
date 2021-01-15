#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
class Solution {
  int count{};
  std::map<int,int> fd,rank;
  int find(int x){
    if(fd.find(x) == fd.end()){
      fd[x] = x;
      count++;
    }
    if(x != fd[x]){
      fd[x] = find(fd[x]);
    }
    return fd[x];
  }

  void merge(int x ,int y){
    auto fx = find(x),fy = find(y);
    if(fx != fy){
      if(rank[fx] < rank[fy]){
        swap(fx,fy);
      }
      fd[fy] = fx;
      if(rank[fx] == rank[fy]) rank[fx]+=1;
      count--;
    }
  }
public:
    int removeStones(vector<vector<int>>& stones) {

      auto size = stones.size();
      for(auto &x:stones){
        merge(x[0],x[1]+100001);
      }
      return size-count;
    }
};
int main(){

}

