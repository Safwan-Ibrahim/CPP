// Created on: 2025-11-07 09:04
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n; cin >> n;
    string S; cin >> S;
    int q; cin >> q;

    vector<vector<int>> Nxt(n, vector<int> (27, -1));
    vector<int> L(27, -1);

    for (int i = n - 1; i >= 0; i--) {
        Nxt[i] = L;
        L[S[i] - 'a'] = i;
    }

    while (q--) {
        string T; cin >> T;
        int id = L[T[0] - 'a'];
        bool yes = id != -1;
        id = max(0, id);
        for (int i = 1; i < T.size(); i++) {
            id = Nxt[id][T[i] - 'a'];
            yes &= id != -1;
            id = max(0, id);
        }
        cout << (yes ? "YES\n" : "NO\n");
    }

    return 0;
} 