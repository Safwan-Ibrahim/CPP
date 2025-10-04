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

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    } 

    vector<int> Cnt(n + 5, 0);
    vector<int> Nxt(n + 5, 0);
    vector<vector<int>> V(n + 5);

    for (int i = 1; i <= n; i++) {
        Cnt[A[i]]++;
        V[A[i]].push_back(i);
        if (Cnt[A[i]] >= A[i]) {
            int cur = V[A[i]].size();
            int prev = cur - A[i];
            int v = V[A[i]][prev];
            Nxt[v] = i;
        }
    }

    vector<int> Mx(n + 5, 0);
    for (int i = n; i >= 1; i--) {
        Mx[i] = Mx[i + 1];
        if (Nxt[i] != 0) Mx[i] = max(Mx[i], A[i] + Mx[Nxt[i] + 1]);
    }

    cout << Mx[1] << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 