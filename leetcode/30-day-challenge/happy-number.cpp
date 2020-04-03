#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
  bool isHappy(int n) {
    map<int, bool> record;
    if (n == 1) {
      return true;
    }
    string num = to_string(n);
    long long ret = 0;
    //cout << record.count(0) <<endl;
    while (record.count(ret) == 0) {
      record[ret] = true;
      ret = 0;
      for (auto i : num) {
        int t = i - '0';
        ret += (t * t);
      }
     // cout<<"ret:"<< ret <<endl;
      if (ret == n)
        return false;
      else if (ret == 1)
        return true;
      else {
        num = to_string(ret);
      }
    }
    return false;
  }
};
int main() {
  Solution s;
  cout << s.isHappy(2) << endl;
  return 0;
}
