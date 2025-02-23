#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll mulm(ll a, ll b, ll m) {
    return (ll)((__int128) a * b % m);
}

ll power(ll x, ll n, ll m) {
    ll ans = 1 % m;
    while(n > 0) {
        if (n & 1) {
            ans = mulm(ans, x, m);
        }
        x = mulm(x, x, m);
        n >>= 1;
    }
    return ans;
}

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a, b, c; 
    while(cin >> a) {
        cin >> b >> c;
        cout << power(a, b, c) << endl;
    }
    return 0;
} 