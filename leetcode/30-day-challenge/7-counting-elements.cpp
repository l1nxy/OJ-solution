#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    int countElements(vector<int> &arr)
    {
        int maxvalue =*max_element(arr.begin(), arr.end());
        int cnt = 0;
        vector<int> mask(maxvalue+1, 0);
        for (auto i : arr)
        {
            mask[i]++;
        }
        for (size_t i = 0; i < maxvalue; i++)
        {
            if (mask[i] != 0 && mask[i +1] != 0)
            {
                cnt += mask[i];
            }
        }
        return cnt;
    }
};
int main(int argc, char *argv[])
{
    Solution s;
    vector<int> v = {1,1,2,2};
    cout << s.countElements(v) << endl;
    return 0;
}
