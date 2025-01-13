#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int power(int x, ll n, int m) {
    vector<int>xp2(63, 0);
    xp2[0] = x * 1; // x ^ (2 ^ 0) = x * 1 = x;
    for (int i = 1; i < 63; i++) {
        xp2[i] = 1LL * xp2[i - 1] * xp2[i - 1] % m;
    }

    int ans = 1 % m;
    for (int i = 0; i < 63; i++) {
        if (n >> i & 1) {
            ans = 1LL * ans * xp2[i] % m;
        }
        xp2[i + 1] = 1LL * xp2[i] * xp2[i] % m;
    }
    return ans;
}

int power2(int x, ll n, int m) { // better
    int xp2 = x * 1; // x ^ (2 ^ 0) = x * 1 = x;
    int ans = 1 % m;
    for (int i = 0; i < 63; i++) {
        if (n >> i & 1) {
            ans = 1LL * ans * xp2 % m;
        }
        xp2 = 1LL * xp2 * xp2 % m;
    }
    return ans;
}

int power3(int x, ll n, int m) { // best
    int xp2 = x; // x ^ (2 ^ 0)
    int ans = 1 % m;
    while(n) {
        if (n & 1) {
            ans = 1LL * ans * xp2 % m;
        }
        xp2 = 1LL * xp2 * xp2 % m;
        n >>= 1;
    }
    return ans;
}

int32_t main()
{   
    int t; cin >> t;
    while(t--) {
        ll x,n,m; cin >> x >> n;
        m = 1e9 + 7;
        //cout << power(x, n, m) << " " << power2(x, n, m) << " " << power3(x, n, m);
        cout << power3(x,n,m) << endl;
    }
    return 0;
} 
