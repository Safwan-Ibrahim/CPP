// Created on: 2025-07-09 16:09
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 17;
int n, x, A[nn];

int get_max() {
    int ans = -1;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += A[i];
        sum %= x;
        if (sum != 0) ans = i;
    }
    return ans;
}

void Try() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    int mx = get_max();
    reverse(A + 1, A + n + 1);
    mx = max(mx, get_max());
    cout << mx << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 