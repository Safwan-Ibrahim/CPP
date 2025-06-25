// Created on: 2025-06-23 16:58
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, k; cin >> n >> k;
    char S[n + 8]; 
    for (int i = 1; i <= n; i++) {
        cin >> S[i];
    }
    
    vector<int>First(k, n + 1);
    vector<int>Min_op(n + 10, 0);
    Min_op[n + 1] = 1;
    for (int i = n; i >= 1; i--) {
        First[S[i] - 'a'] = i;
        int last = -1;
        for (int j = 0; j < k; j++) {
            last = max(First[j], last);
        }
        Min_op[i] = 1 + Min_op[last + 1];
    }

    First = vector<int>(k, n + 1);
    vector<vector<int>> Go(n + 1, vector<int>(k));
    for (int i = n; i >= 1; i--) {
        First[S[i] - 'a'] = i;
        for (int j = 0; j < k; j++) {
            Go[i][j] = First[j];
        }
    }
    
    int q; cin >> q;
    while(q--) {
        string S; cin >> S;
        int id = 1, p = 0;
        while(id <= n && p < S.size()) {
            id = Go[id][S[p] - 'a'] + 1, p++;
        }
        if (p < S.size() || id == n + 2) cout << 0 << endl;
        else cout << Min_op[id] << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; //cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 