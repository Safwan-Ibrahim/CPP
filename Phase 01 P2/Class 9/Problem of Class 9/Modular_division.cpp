#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int power(int x, int n, int m) {
    int ans = 1;
    while(n > 0) {
        if (n & 1) {
            ans = 1LL * ans * x % m;
        }
        x = 1LL * x * x % m;
        n >>= 1;
    }
    return ans;
}

int inverse(int x, int m) {
    return power(x, m - 2, m);
}

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a,b,n; cin >> a >> b >> n;
    a %= n;
    int x = inverse(b, n);
    cout << 1LL * a * x % n << endl;
    
    return 0;
} 