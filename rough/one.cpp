// Created on: 2025-05-23 16:51
// Author: Safwan_Ibrahim

#include <iostream>
using namespace std;

#define ll unsigned long long
#define endl '\n'

ll n, k;

ll get_and(ll x, ll y) {
    ll ans = 0;
    for (int i = 0; x > 0; i++) {
        if ((x & 1) && (y & 1)) {
            if (y - x <= 1) ans |= (1ULL << i);
        }
        x >>= 1;
        y >>= 1;
    }
    return ans;
} 

void Try() {
    // scanf("%llu %llu", &n, &k);
    // if (n == 0) {
    //     if (k == 0) printf("%d\n", 0);
    //     else printf("%d\n", -1);
    //     return;
    // }
    // ll lo = n, hi = 5e18 + 3, ans;
    // bool yes = false;
    // while(lo <= hi) {
    //     ll mid = lo + (hi - lo) / 2;
    //     ll and_ = get_and(n, mid);
    //     if (and_ <= k) {
    //         hi = mid - 1;
    //         if (and_ == k) {
    //             ans = mid; yes = true;
    //         }
    //     }
    //     else {
    //         lo = mid + 1;
    //     }
    // }
    // if (yes) printf("%llu\n", ans);
    // else printf("%d\n", -1);
    cout << "how\n";
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 