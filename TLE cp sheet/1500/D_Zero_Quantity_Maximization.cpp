// Created on: 2025-05-15 03:51
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 8;
int n, A[nn], B[nn];

tuple<int, int, bool> get_ratio(int x, int y) {
    int g = gcd(x, y);
    return {abs(x / g), abs(y / g), 1LL * x * y >= 0};
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> B[i];
    }
    
    int mx = 0; int ans = 0;
    map<tuple<int, int, bool>, int>Mp;
    for (int i = 1; i <= n; i++) {
        if (A[i] == B[i] && B[i] == 0) {
            ans++; continue;
        }
        if (A[i] == 0) {
            continue;
        }
        if (B[i] == 0) {
            Mp[{0, 0, 0}]++; continue;
        }
        auto [x, y, m] = get_ratio(B[i], A[i]);
        Mp[{x, y, m}]++;
    }

    for (auto [x, y] : Mp) {
        mx = max(mx, y);
    }
    cout << mx + ans << endl;
    
    return 0;
} 