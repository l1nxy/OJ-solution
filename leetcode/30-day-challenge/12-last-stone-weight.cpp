#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    int judge(int x, int y)
    {
        if (x == y)
        {
            return 0;
        }
        else
        {
            return y - x;
        }
    }
    int helper(vector<int> &stones)
    {
        if (stones.size() == 1)
            return stones[0];
        if (stones.empty() == true)
            return 0;

        sort(stones.begin(), stones.end());
        int y = stones[stones.size() - 1];
        int x = stones[stones.size() - 2];
        stones.pop_back();
        stones.pop_back();
        stones.push_back(judge(x, y));
    }
  public:
    int lastStoneWeight(vector<int> &stones)
    {
        return helper(stones);
    }
};
int main()
{
}
