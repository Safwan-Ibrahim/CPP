// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, A[nn];

void Try() {
    cin >> n;

    vector<int> O, E;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (x & 1) O.push_back(x);
        else E.push_back(x);
    }
    
    if (O.empty()) {
        cout << 0 << endl; return;
    }

    ll ans = accumulate(E.begin(), E.end(), 0LL);
    
    sort(O.rbegin(), O.rend());
    int lim = (O.size() + 1) / 2;
    for (int i = 1; i <= lim; i++) {
        ans += O[i - 1];
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