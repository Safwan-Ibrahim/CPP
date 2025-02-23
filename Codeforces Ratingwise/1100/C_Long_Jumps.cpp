// Created on: 2025-01-30 17:06
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 2e5 + 9;
int A[N], Mp[N];

void solve() {
    int n; cin >> n;

    int A[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    memset(Mp, 0, (n + 2) * 4);
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = i; j <= n; j += A[j]) {
            sum += A[j];
            if (Mp[j] > 0) {
                break;
            }
            Mp[j] += sum;
        }
    }

    int mx = -1;
    for (int i = 1; i <= n; i++) {
        mx = max(Mp[i], mx);
    }
    
    cout << mx << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
} 