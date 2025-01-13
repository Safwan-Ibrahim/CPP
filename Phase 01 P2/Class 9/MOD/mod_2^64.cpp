#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define endl '\n'

ll power(ll x, ll n) { // mod under 2^64;
    ll xp = x, ans = 1;
    while(n) {
        if (n & 1) {
            ans *= xp;
        }
        xp *= xp;
        n >>= 1;
    }
    return ans;
}

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll a = 1e9 + 7, b = 1e18; // ll = unsigned long long
    cout << power(a,b) << endl; 
    
    return 0;
} 