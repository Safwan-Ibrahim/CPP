// Created on: 2025-07-16 22:08
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
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
    int prm = 0;
    map<int, int>Prm, Sp;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (Pf[x].size() == 1) {
            Prm[x]++;
            prm++;
        }
        else if (Pf[x].size() == 2) {
            Sp[x]++;
        }
    }
    
    ll ans = 0;
    for (auto [x, y] : Prm) {
        prm -= y;
        ans += 1LL * y * prm;
    }

    for (auto [x, y] : Sp) {
        ans += 1LL * y * (Prm[Pf[x].front()] + (Pf[x].back() != Pf[x].front() ? Prm[Pf[x].back()] : 0));
        ans += 1LL * y * (y + 1) / 2;
    }

    cout << ans << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t; prec();
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 