// Created on: 2025-03-19 23:26
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 75;
double A[N];

void Try() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    int mx = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int cnt = 0;
            double inc = (A[j] - A[i]) / (j - i);
            for (int k = 1; k <= n; k++) {
                if (abs(A[i] + ((k - i) * inc) - A[k]) < 1e-9) {
                    cnt++;
                }
            }
            mx = max(mx, cnt);
        }
    }

    cout << n - mx << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 