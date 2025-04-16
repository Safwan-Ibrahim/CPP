// Created on: 2025-04-15 15:49
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 5e3 + 8;
string S;
bool Ip[nn][nn];
int Pref[nn][nn];

void it_dp() {
    for (int i = 0; i < S.size(); i++) {
        Ip[i][i] = true;
    }

    for (int len = 2; len <= S.size(); len++) {
        for (int i = 0; i + len - 1 < S.size(); i++) {
            int j = i + len - 1;
            Ip[i][j] = S[i] == S[j];
            if (len != 2) {
                Ip[i][j] &= Ip[i + 1][j - 1];
            }
        }
    }

    for (int i = 0; i < S.size(); i++) {
        for (int j = 0; j < S.size(); j++) {
            Pref[i][j] = Ip[i][j];
            if (i != 0) {
                Pref[i][j] += Pref[i - 1][j];
            }
            if (j != 0) {
                Pref[i][j] += Pref[i][j - 1];
            }
            if (i != 0 && j != 0) {
                Pref[i][j] -= Pref[i - 1][j - 1];
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> S;
    int q; cin >> q;
    it_dp();
    while(q--) {
        int l, r; cin >> l >> r;
        l--, r--;
        int ans = Pref[r][r];
        if (l != 0) {
            ans -= Pref[l - 1][r];
            ans -= Pref[r][l - 1];
            ans += Pref[l - 1][l - 1];
        }
        cout << ans << endl;
    }
    
    
    return 0;
} 