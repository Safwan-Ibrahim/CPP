// Created on: 2025-08-01 14:33
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e6 + 17;

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

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    prec();
    map<int, map<int, int>>Mx;
    int n; cin >> n;
    char ty; int u, v;
    for (int i = 1; i <= n; i++) {
        cin >> ty; 
        if (ty == '+') {
            cin >> u >> v;
            for (auto x : Pf[u]) {
                Mx[x][v]++;
            }
        }
        else if (ty == '-') {
            cin >> u >> v;
            for (auto x : Pf[u]) {
                Mx[x][v]--;
                if (Mx[x][v] == 0) {
                    Mx[x].erase(v);
                }
            }
        }
        else {
            cin >> u;
            int mx = 0;
            for (auto x : Pf[u]) {
                if (Mx[x].size()) {
                    mx = max(mx, Mx[x].rbegin()->first);
                }
            }
            cout << mx << endl;
        }
    }
    
    return 0;
} 