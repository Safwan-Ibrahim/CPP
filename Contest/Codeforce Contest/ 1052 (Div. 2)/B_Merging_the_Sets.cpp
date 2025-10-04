// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, m; cin >> n >> m;

    vector<int> Cnt(m + 1, 0);
    vector<int> A[n + 5];
    int s = 0;
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        for (int j = 1; j <= k; j++) {
            int x; cin >> x;
            A[i].push_back(x);
            Cnt[x]++;
            if (Cnt[x] == 1) s++;
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (auto x : A[i]) {
            Cnt[x]--;
            if (Cnt[x] == 0) s--;
        }
        ans += s == m;
        for (auto x : A[i]) {
            if (Cnt[x] == 0) s++;
            Cnt[x]++;
        }

        if (ans > 1) {
            cout << "YES\n"; return;
        }
    }

    cout << "NO\n";
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 