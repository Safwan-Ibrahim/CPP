#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int power(int x, int n, int m) {
    int ans = 1 % m;
    while(n > 0) {
        if (n & 1) {
            ans = 1LL * x * ans % m;
        }
        x = 1LL * x * x % m;
        n >>= 1;
    }
    return ans;
}

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int b, p, m; 
    while(cin >> b) {
        cin >> p >> m;
        cout << power(b, p, m) << endl;
    }
    
    return 0;
} 