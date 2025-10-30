// Created on: 2025-10-30 07:06
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e6 + 17;

int Sp[nn];
vector<int>Prime;
vector<bool>Gone(nn, false);
vector<int> Pf[nn];

void prec() {
    for (int i = 2; i * i < nn - 2; i++) {
        if (!Gone[i]) {
            for (int j = i * i; j < nn - 2; j += i) {
                Gone[j] = true;
            }
        }
    }

    for (int i = 2; i < nn - 2; i++) {
        if (!Gone[i]) {
            Prime.push_back(i);
        }
    }

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
    int n; cin >> n;
    for (int i = 1; i + 5 <= n; i++) {
        if (!Gone[i ^ (i + 5)]) {
            cout << i << " " << i + 5 << endl;
        }
    }
    
    
    return 0;
} 