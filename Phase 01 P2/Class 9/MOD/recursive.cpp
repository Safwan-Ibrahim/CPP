#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int powr(int x, ll n, int m) {
    if (n == 0) {
        return 1;
    }
    int crnt = powr(x, n / 2, m);
    if (n & 1) {
        return 1LL * crnt * crnt % m * x % m;
    }
    else {
        return 1LL * crnt * crnt % m;
    }
}

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll x,n,m; cin >> x >> n >> m;
    cout << powr(x,n,m) << " ";
    
    return 0;
} 