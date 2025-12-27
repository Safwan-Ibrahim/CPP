// Created on: 2025-06-30 20:14
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17, mod = 1e9 + 7;
int n, k, A[nn];

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

void Try() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    vector<int>B;
    map<int, int>Mp;
    Mp[0]++;
    for (int i = 1; i <= n; i++) {
        Mp[A[i]]++;
        B.push_back(A[i]);
    }
    sort(B.begin(), B.end());
    B.erase(unique(B.begin(), B.end()), B.end());

    int mul = 1;
    for (auto [x, y] : Mp) {
        mul = 1LL * mul * y % mod;
        Mp[x] = mul;
    }

    int ans = 0;
    for (int i = 0; i + k - 1 < B.size(); i++) {
        if (B[i] + k - 1 == B[i + k - 1]) {
            auto it = Mp.find(B[i]); it--;
            int cont = 1LL * Mp[B[i + k - 1]] * power(it->second, mod - 2, mod) % mod;
            ans += cont; 
            if (ans >= mod) ans -= mod;
        }
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