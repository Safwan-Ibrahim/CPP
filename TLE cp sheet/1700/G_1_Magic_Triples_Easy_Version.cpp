// Created on: 2025-07-01 16:35
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17, m = 1e6 + 17;
int n, A[nn], Cnt[m]; 

ll np3(int x) {
    if (x < 3) return 0;
    return 1LL * x * (x - 1) * (x - 2);
}

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        Cnt[A[i]]++;
    }
    
    vector<int>B(n);
    for (int i = 1; i <= n; i++) {
        B[i - 1] = A[i];
    }
    sort(B.begin(), B.end());
    B.erase(unique(B.begin(), B.end()), B.end());

    ll ans = 0;
    for (auto x : B) {
        ans += np3(Cnt[x]);
        for (int i = 2; x * i * i <= 1000000; i++) {
            ll comb = 1LL * Cnt[x] * Cnt[x * i] * Cnt[x * i * i];
            ans += comb;
        }
        Cnt[x] = 0;
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