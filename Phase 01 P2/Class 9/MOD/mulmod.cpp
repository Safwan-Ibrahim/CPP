#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll mul(ll a, ll b, ll m) {
    if(a < b) {
        swap(a,b);
    }
    ll ans = 0, xp2 = b;
    while(b) {
        if (b & 1) {
            ans = (xp2 + ans) % m;
        }
        xp2 = (xp2 + xp2) % m;
        b >>= 1;
    }
    return ans;
}

ll mul2(ll a, ll b, ll m) {
    return (ll)((__int128) a * b % m);
}

int32_t main()
{   
    ll a,b; 
    a = 1e18, b = 1e18;
    ll m = (ll)1e18 + 7;// print a * b;
    cout << mul(a,b,m) << endl; 
    return 0; 
} 