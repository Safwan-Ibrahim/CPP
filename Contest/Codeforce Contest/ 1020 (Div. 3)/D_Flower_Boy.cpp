// Created on: 2025-04-24 21:22
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 8, inf = 2e9;
int n, m, A[nn], B[nn];

void Try() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    for (int i = 1; i <= m; i++) {
        cin >> B[i];
    } 
    
    vector<int>Pref(m + 5, inf), Suf(m + 5, -1);
    int pb = 1;
    Pref[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (A[i] >= B[pb]) {
            Pref[pb] = i;
            pb++;
        }
        if (pb == m + 1) {
            cout << 0 << endl; return;         
        }
    }

    pb = m;
    Suf[m + 1] = n + 1;
    for (int i = n; i >= 1; i--) {
        if (A[i] >= B[pb]) {
            Suf[pb] = i;
            pb--;
        }
    }

    int ans = inf;
    for (int i = 1; i <= m; i++) {
        if (Pref[i - 1] < Suf[i + 1]) {
            ans = min(ans, B[i]);
        }
    }

    cout << (ans == inf ? -1 : ans) << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 