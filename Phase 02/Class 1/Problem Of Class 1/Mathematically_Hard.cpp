// Created on: 2025-01-04 18:46
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 5e6 + 9;
int spf[N];
ll ans[N];

void prec_alculate(int x) {
    
}

void calculate() {
    for (int i = 1; i < N; i++) {
        spf[i] = i;
    }

    for (int i = 2; i < N; i++) {
        for (int j = i; j < N; j += i) {
            spf[j] = min(i, spf[j]);
        }
    }

    for (int i = 2; i < N; i++) {
        prec_alculate(i);
    }
}

void solve(int t) {
    int a, b; cin >> a >> b;
    cout << "Case " << t << ": ";
    cout << ans[a] + ans[b] << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    calculate();
    int t = 1; cin >> t;
    int c = 1;
    while(t--) solve(c++);
    return 0;
} 