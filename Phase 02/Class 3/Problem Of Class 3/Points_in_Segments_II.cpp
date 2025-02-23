// Created on: 2025-01-25 21:15
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 5e4 + 9;
int L[N], R[N], A[N], Q[N];

void solve() {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> L[i] >> R[i];
    }
    
    map<int, int>Dif;
    for (int i = 1; i <= q; i++) {
        int x; cin >> x;
        Dif[x] = 0;
        Q[i] = x; 
    }

    for (int i = 1; i <= n; i++) {
        Dif[L[i]]++;
        Dif[R[i] + 1]--;
    }
    
    int sum = 0;
    for (auto [x, y] : Dif) {
        Dif[x] += sum;
        sum = Dif[x];
    }

    for (int i = 1; i <= q; i++) {
        cout << Dif[Q[i]] << endl;
    }    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ":" << endl;
        solve();
    }
    return 0;
} 