// Created on: 2025-10-30 08:58
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 17;
int n, L[nn], D[nn], C[nn];

void Try() {
    cin >> n;

    set<int> St;
    for (int i = 1; i <= n; i++) {
        cin >> L[i];
    }
    for (int i = 1; i <= n; i++) {
        int x; cin >> x; St.insert(x);
    }
    for (int i = 1; i <= n; i++) {
        cin >> C[i];
    }
    
    sort(L + 1, L + n + 1, greater<>());
    sort(C + 1, C + n + 1, greater<>());

    for (int i = 1; i <= n; i++) {
        auto it = St.lower_bound(L[i]);
        D[i] = *it - L[i];
        St.erase(it);
    }
    
    sort(D + 1, D + n + 1);
    
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += 1LL * C[i] * D[i];
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