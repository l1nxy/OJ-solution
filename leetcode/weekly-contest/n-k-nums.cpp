#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {
        int invert_num = 0;
        while(n--> 1){
            int mid = pow(2,n-1);
            if(k == mid){
                return invert_num % 2 == 0 ? '0':'1';
            }
            if(k > mid){
                k = mid*2 - k;
                invert_num++;
            }
        }
        return invert_num % 2 == 0 ? '0' : '1';
    }
};
int main(){

}
