// Created on: 2025-03-17 21:44
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, m; cin >> n >> m;
    vector<int>A(m, 0);
    for (int i = 0; i < m; i++) {
        cin >> A[i];
        A[i] = min(A[i], n - 1);
    }

    sort(A.begin(), A.end());
    vector<ll>S(m + 5, 0);
    ll sum = 0;
    for (int i = A.size() - 1; i >= 0; i--) {
        sum += A[i];
        S[i] = sum;
    }

    ll ans = 0;
    for (int i = 0; i < A.size(); i++) {
        int need = n - A[i];
        auto it = lower_bound(A.begin(), A.end(), need);
        if (it == A.end()) {
            continue;
        }
        int id = it - A.begin();
        int value = *it;
        ans += S[id];
        int cnt = m - id;
        if (value <= A[i]) {
            ans -= A[i];
            cnt--;
        }
        ans -= 1LL * (need - 1) * cnt;
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