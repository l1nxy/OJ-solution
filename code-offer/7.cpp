#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int ret = 0;
        if(rotateArray.size() == 0) return ret;
        int start = 0;
        int end = rotateArray.size()-1;
        while(start < end)
        {
            if(rotateArray[start] < rotateArray[end]) return rotateArray[start];
            else
            {
                int mid = (start + end) /2;
                if(rotateArray[mid] >= rotateArray[start]) start  = mid+1;
                else end = mid;
            }
        }
        return rotateArray[start];
    }
};
int main(int argc, char *argv[])
{

    return 0;
}

