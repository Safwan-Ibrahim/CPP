// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
ll n, Pa[nn], Pb[nn], Sa[nn], Sb[nn];
char S[nn];

void Try() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> S[i];
    }

    ll pa = 0, pb = 0, la = 0, lb = 0;
    for (int i = 1; i <= n; i++) {
        if (S[i] == 'b') {
            if (la) {
                pb += i - la;
                la++;
            }
            if (!lb) lb = i;
        }
        else {
            if (lb) {
                pa += i - lb;
                lb++;
            }
            if (!la) la = i;
        }
        Pa[i] = pa, Pb[i] = pb;
    }
    
    ll sa = 0, sb = 0; la = 0, lb = 0;
    for (int i = n; i >= 1; i--) {
        if (S[i] == 'b') {
            if (la) {
                sb += la - i;
                la--;
            }
            if (!lb) lb = i;
        }
        else {
            if (lb) {
                sa += lb - i;
                lb--;
            }
            if (!la) la = i;
        }
        Sa[i] = sa, Sb[i] = sb;
    }

    Sa[n + 1] = Sb[n + 1] = 0;
    ll ans = 1e18;
    for (int i = 0; i <= n; i++) {
        ans = min(ans, Pa[i] + Sa[i + 1]);
        ans = min(ans, Pb[i] + Sb[i + 1]);
    }

    cout << ans << endl;    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 