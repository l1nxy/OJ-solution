#include <bits/stdc++.h>
using namespace std;

using LL = long long;

int main()
{
    LL n, k;
    cin >> n >> k;

    if (n % k == 0)
        cout << 0 << endl;
    else
    {
        n %= k;
        cout << min(n, k - n) << endl;
    }
    return 0;
}