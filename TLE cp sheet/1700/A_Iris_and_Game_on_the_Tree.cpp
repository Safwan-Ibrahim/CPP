// Created on: 2025-06-28 16:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 17;
vector<int> G[nn];
int n; char S[nn];

void Try() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        cin >> S[i];
    }

    int q = 0, one = 0, zero = 0, non_leaf = 0;
    for (int i = 2; i <= n; i++) {
        if (G[i].size() == 1) {
            if (S[i] == '1') one++;
            else if (S[i] == '0') zero++;
            else q++;
        }
        else non_leaf += S[i] == '?';
    }

    int ans = 0;
    if (S[1] != '?') {
        if (S[1] == '1') ans += zero;
        else ans += one;
        ans += (q + 1) / 2;
    }
    else if (one != zero) {
        ans += max(one, zero);
        ans += q / 2;
    }
    else {
        ans += one;
        ans += (non_leaf % 2 == 1 ? (q + 1) / 2 : q / 2);
    }
    
    cout << ans << endl;

    for (int i = 1; i <= n; i++) {
        G[i].clear();
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 