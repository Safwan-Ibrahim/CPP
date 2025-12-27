// Created on: 2025-11-24 19:28
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    string S; cin >> S;
    int n = S.size();

    S = "#" + S;
    vector<vector<int>> F(n + 1, vector<int> (27, 0));

    vector<int> Sum(27, 0);
    for (int i = 1; i <= n; i++) {
        Sum[S[i] - 'a']++;
        F[i] = Sum;
    }

    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        vector<int> R = F[r];
        vector<int> L = F[l - 1];

        int cnt = 0;
        for (int i = 0; i < 27; i++) {
            cnt += (R[i] - L[i]) > 0;
        }

        cout << ((r - l == 0 || cnt > 2 || S[l] != S[r]) ? "Yes\n" : "No\n");
    }

    return 0;
} 