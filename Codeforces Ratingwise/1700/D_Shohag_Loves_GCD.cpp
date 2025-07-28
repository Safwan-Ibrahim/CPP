// Created on: 2025-07-17 18:07
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 3e5 + 17;
int n, m, A[nn];

void Try() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> A[i];
    }
    sort(A + 1, A + m + 1, greater<int>());
    vector<int>Ans(n + 1, 0);
    vector<vector<int>>Cant(n + 1, vector<int>{});
    
    for (int i = 1; i <= n; i++) {
        int val = -1;
        sort(Cant[i].begin(), Cant[i].end());
        Cant[i].erase(unique(Cant[i].begin(), Cant[i].end()), Cant[i].end());
        reverse(Cant[i].begin(), Cant[i].end());

        for (int j = 1, p = 0; j <= m; j++, p++) {
            if (p == Cant[i].size() || A[j] != Cant[i][p]) {
                val = A[j]; break;
            } 
        }
        if (val == -1) {
            cout << val << endl; return;
        }
        Ans[i] = val;
        for (int j = i + i; j <= n; j += i) {
            Cant[j].push_back(val);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << Ans[i] << " ";
    }
    cout << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 