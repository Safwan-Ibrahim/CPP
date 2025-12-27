// Created on: 2025-11-20 12:16
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17, mod = 998244353;
set<int> G[nn]; 
int n, k, A[nn], B[nn], Id[nn];

void erase(int u) {
    int cnt = 0, a, b;
    for (auto v : G[u]) {
        G[v].erase(u);
        cnt++;
        if (cnt == 1) a = v;
        if (cnt == 2) b = v;
    }

    if (cnt == 2) {
        G[a].insert(b);
        G[b].insert(a);
    }
}

void Try() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        Id[A[i]] = i;
    }
    
    set<int> St;
    for (int i = 1; i <= k; i++) {
        cin >> B[i];
        St.insert(B[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        G[i].clear();
        if (i - 1 >= 1) {
            G[i].insert(i - 1);
        }
        if (i + 1 <= n) {
            G[i].insert(i + 1);
        }
    }
    
    int ans = 1;
    for (int i = 1; i <= k; i++) {
        int id = Id[B[i]];
        St.erase(B[i]); 

        int er = 0, cnt = 0;
        for (auto x : G[id]) {
            if (!St.count(A[x])) {
                er = x, cnt++;
            }
        }

        if (er) erase(er);
        ans = 1LL * ans * cnt % mod;
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