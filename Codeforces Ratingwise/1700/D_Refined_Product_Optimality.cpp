// Created on: 2025-07-17 01:11
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17, mod = 998244353;
int n, q, A[nn], B[nn];

int power(int x, int n, int m) {
    int ans = 1 % m;
    while(n > 0) {
        if (n & 1) {
            ans = 1LL * ans * x % m;
        }
        n >>= 1;
        x = 1LL * x * x % m;
    }
    return ans;
}

int inverse(int x) {
    return power(x, mod - 2, mod);
}

void Try() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> B[i];
    }

    vector<int> C(A + 1, A + n + 1);
    vector<int> D(B + 1, B + n + 1);
    sort(C.begin(), C.end()), sort(D.begin(), D.end());

    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans = 1LL * ans * min(C[i], D[i]) % mod;
    }

    cout << ans << " ";
    int ty, id;
    for (int _ = 1; _ <= q; _++) {
        cin >> ty >> id;
        int last_id;
        if (ty == 1) {
            last_id = upper_bound(C.begin(), C.end(), A[id]) - C.begin() - 1;
            C[last_id]++;
            if (C[last_id] <= D[last_id]) {
                ans = 1LL * ans * inverse(C[last_id] - 1) % mod;
                ans = 1LL * ans * C[last_id] % mod;
            }
        }
        else {
            last_id = upper_bound(D.begin(), D.end(), B[id]) - D.begin() - 1;
            D[last_id]++;
            if (D[last_id] <= C[last_id]) {
                ans = 1LL * ans * inverse(D[last_id] - 1) % mod;
                ans = 1LL * ans * D[last_id] % mod;
            }
        }
        if (ty == 1) A[id]++;
        else B[id]++;
        cout << ans << " ";
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