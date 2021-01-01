#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        flowerbed.push_back(0);
        flowerbed.insert(flowerbed.begin(),0);
        for (auto i = 1; i < flowerbed.size()-1;)
        {
                if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
                {
                    flowerbed[i] = 1;
                    n--;
                    i+=2;
                }else{
                    i+=1;
                }
        }
        cout << n << endl;
        return n <= 0;
    }
};
int main()
{
    Solution s;
    vector<int> v ={1,0,0,0,1,0,0};
    std::cout <<s.canPlaceFlowers(v, 2)<<std::endl;
}
