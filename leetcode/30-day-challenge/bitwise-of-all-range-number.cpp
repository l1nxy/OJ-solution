#include <iostream>

using namespace std;
class Solution{
    public:
        int rangeBitWiseAnd(int m ,int n){
            int i = 0;
            while(m != n){
                n >>=1;
                m >>=1;
                ++i;
            }
            return (m << i);
        }
};
int main(){
    return 0;
}
