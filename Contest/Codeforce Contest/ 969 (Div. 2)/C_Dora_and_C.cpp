// Created on: 2025-02-02 18:30
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5 + 8;
int A[N];

void Try() {
    int n, a, b; cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    int g = gcd(a, b);
    for (int i = 1; i <= n; i++) {
        A[i] %= g;
    }
    
    sort(A + 1, A + n + 1);
    int ans = A[n] - A[1];

    for (int i = 1; i + 1 <= n; i++) {
        ans = min(A[i] + g - A[i + 1], ans);
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