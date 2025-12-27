// Created on: 2025-05-05 08:23
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 8;
vector<int> G[nn];
bool R[nn];

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    int root;
    for (int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        if (!y) {
            R[i] = true;
        }
        if (x == -1) {
            root = i;
        }
        else {
            G[x].push_back(i);
        }
    }

    vector<int>Ans;
    for (int i = 1; i <= n; i++) {
        if (i == root) {
            continue;
        }
        int res = R[i];
        for (auto v : G[i]) {
            res |= R[v];
        }
        if (!res) {
            Ans.push_back(i);
        }
    }

    if (Ans.empty()) {
        cout << -1 << endl;
    }
    else {
        for (auto x : Ans) {
            cout << x << " ";
        }
        cout << endl;
    }
    
    return 0;
} 