// Created on: 2025-07-01 22:43
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int GD[nn];

void prec() {
    vector<bool>Gone(nn, false);
    vector<int>Prime;
    for (int i = 2; i * i < nn; i++) {
        if (!Gone[i]) {
            for (int j = i * i; j < nn; j += i) {
                Gone[j] = true;
            }
        }
    }

    for (int i = 2; i < nn; i++) {
        for (int j = i + i; j < nn; j += i) {
            GD[j] = max(GD[j], i);
        }
    }

    for (int i = 2; i < nn; i++) {
        if (!Gone[i]) {
            Prime.push_back(i);
            GD[i] = i;
        }
    }
}

void Try() {
    int n; cin >> n;
    set<int>St;
    vector<int>Ans(n + 3, 0);
    for (int i = 1; i <= n; i++) {
        Ans[i] = i;
        St.insert(i);
    }
    
    vector<bool>gone(n + 3, false);
    for (int i = n; i >= 1; i--) {
        if (!gone[i]) {
            swap(Ans[i], Ans[GD[i]]);
            gone[GD[i]] = true;
        }
    }
    Ans[1] = 1;
    if (Ans[2] == 2 && n > 3) swap(Ans[2], Ans[4]);
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