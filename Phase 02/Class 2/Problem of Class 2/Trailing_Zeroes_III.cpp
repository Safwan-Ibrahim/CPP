// Created on: 2025-01-09 14:02
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll get_num (int fact) {
    ll ans = 0;
    // ll p5 = 1;
    // while(p5 * 5 <= fact) {
    //     p5 *= 5;
    //     ans += fact / p5;
    // }
    while(fact) {
        ans += fact / 5;
        fact /= 5;
    }
    return ans;
}

void solve2(int t) {
    int n; cin >> n;

    int ans = 0;
    int lo = 1, hi = 5e8;
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        ll num5 = get_num(mid); 
        if (num5 > n) {
            hi = mid - 1;
        }
        else if (num5 < n) {
            lo = mid + 1;
        }
        else {
            ans = mid; 
            hi = mid - 1;
        }
    }

    cout << "Case " << t << ": ";
    if (ans) {
        cout << ans << endl;
    }
    else {
        cout << "impossible\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t = 1; cin >> t; int c = 1;
    while(t--) solve2(c++);
    return 0;
} 