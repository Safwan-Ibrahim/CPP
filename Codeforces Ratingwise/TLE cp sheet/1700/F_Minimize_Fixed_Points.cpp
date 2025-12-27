// Created on: 2025-07-04 00:57
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 107;
int n;

int Sp[nn];
vector<int> Pf[nn];

void prec() {
    for (int i = 1; i < nn - 2; i++) {
        Sp[i] = i;
    }

    for (int i = 2; i * i < nn - 2; i++) {
        if (Sp[i] == i) {
            for (int j = i * i; j < nn - 2; j += i) {
                Sp[j] = min(Sp[j], i);
            }
        }
    }

    for (int i = 2; i < nn - 2; i++) {
        int n = i;
        while(n > 1) {
            Pf[i].push_back(Sp[n]);
            n /= Sp[n];
        }
    }
}

void Try() {
    cin >> n;
    vector<vector<int>>Gp(n + 1);
    for (int i = 2; i <= n; i++) {
        Gp[Pf[i].back()].push_back(i);
    }
    
    vector<int>Ans(n + 1);
    for (int i = 1; i <= n; i++) {
        Ans[i] = i;
    }

    for (int i = 2; i <= n; i++) {
        int si = Gp[i].size();
        for (int j = 0; j < si; j++) {
            Ans[Gp[i][j]] = Gp[i][(j + 1) % si];
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << Ans[i] << " ";
    }
    cout << endl;
    
}
int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t; prec();
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 