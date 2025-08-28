// Created on: 2025-06-17 09:38
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
ll A[nn], k, mx, sum;
int n;

bool ok(int x) {
    ll need = (sum + x - 1) / x;
    need = max(need, mx);
    return need * x <= sum + k;
}

void Try() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    sum = 0, mx = 0;
    for (int i = 1; i <= n; i++) {
        sum += A[i];
        mx = max(mx, A[i]);
    }

    for (int i = n; i >= 1; i--) {
        if ((i - sum % i) % i <= k && ok(i)) {
            cout << i << endl; return;
        }
    }
    assert(false);

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 