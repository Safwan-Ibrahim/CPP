// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, A[nn];

void Try() {
    cin >> n;

    int tt = 0;
    for (int i = 1; i <= n; i++) {
        char c; cin >> c;
        A[i] = (c == 'a' ? 1 : -1);
        tt += A[i];
    }
    
    int sum = 0, mn = n;
    map<int, int> Mp;
    Mp[0] = 0;
    
    for (int i = 1; i <= n; i++) {
        sum += A[i];
        Mp[sum] = i;
        if (Mp.find(sum - tt) != Mp.end()) {
            mn = min(mn, i - Mp[sum - tt]);
        }
    }

    cout << (mn == n ? -1 : mn) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 