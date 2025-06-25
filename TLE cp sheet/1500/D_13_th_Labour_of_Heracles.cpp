// Created on: 2025-05-10 04:01
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 8;
int n, A[nn], Cnt[nn];

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        Cnt[u]++;
        Cnt[v]++;
    }

    ll ans = 0;
    vector<int>V;
    for (int i = 1; i <= n; i++) {
        ans += A[i];
        while(Cnt[i] > 1) {
            V.push_back(A[i]);
            Cnt[i]--;
        }
        Cnt[i]--;
    }

    sort(V.begin(), V.end());
    for (int i = 1; i < n; i++) {
        cout << ans << " ";
        if (V.size()) {
            ans += V.back();
            V.pop_back();
        }
    }
    cout << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 