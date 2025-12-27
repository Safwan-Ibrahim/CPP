// Created on: 2025-05-27 05:04
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, Pref[6][nn];
char S[nn];

void calc(int x, vector<char>V) {
    int p = 0;
    vector<char> Tmp(n + 3);
    for (int i = 1; i <= n; i++) {
        Tmp[i] = V[p++];
        if (p == 3) p = 0;
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += Tmp[i] != S[i];
        Pref[x][i] = sum;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> S[i];
    }

    int cnt = 0;
    vector<char>V = {'a', 'b', 'c'};
    do {
        calc(cnt++, V);
    }
    while(next_permutation(V.begin(), V.end()));

    while(m--) {
        int mn = 1e9;
        int l, r; cin >> l >> r;
        for (int i = 0; i < 6; i++) {
            mn = min(Pref[i][r] - Pref[i][l - 1], mn);
        }
        cout << mn << endl;
    }

    return 0;
} 