// Created on: 2025-12-09 18:47
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17, mm = 2e5;
int n, m, q, A[2][nn];
bool Posp[nn], Negp[nn], Negv[2][nn], Posv[2][nn];

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> n >> m >> q;

    vector<ll> Cnt(2, 0);
    for (int j = 0; j <= 1; j++) {
        for (int i = 1; i <= (!j ? n : m); i++) {
            cin >> A[j][i];
            Cnt[j] += A[j][i];
        }
    }

    for (int j = 0; j <= 1; j++) {
        for (int i = 1; i <= (!j ? n : m); i++) {
            if (abs(Cnt[j] - A[j][i]) <= mm) {
                if ((Cnt[j] - A[j][i]) >= 0){
                    Posv[j][abs(Cnt[j] - A[j][i])] = 1;
                }
                else {
                    Negv[j][abs(Cnt[j] - A[j][i])] = 1;
                }
            }
        }
    }

    if (Posv[0][0] || Posv[1][0]) Posp[0] = Negp[0] = 1;
    for (int i = 1; i <= mm; i++) {
        for (int j = 1; j * j <= i; j++) {

            if (i % j) continue;
            int nj = i / j;

            for (int k = 0; k <= 1; k++) {
                if (Posv[k][j] && Posv[k ^ 1][nj] || Negv[k][j] && Negv[k ^ 1][nj]) {
                    Posp[i] = 1;
                }
                if (Negv[k][j] && Posv[k ^ 1][nj] || Posv[k][j] && Negv[k ^ 1][nj]) {
                    Negp[i] = 1;
                }
            }
        }
    }

    for (int i = 1; i <= q; i++) {
        int x; cin >> x;
        if (x < 0) {
            cout << (Negp[abs(x)] ? "YES\n" : "NO\n");
        }
        else {
            cout << (Posp[x] ? "YES\n" : "NO\n");
        }
    }


    return 0;
} 