// Created on: 2025-08-28 07:08
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, t, root; 
vector<int> G[nn];

bool Win(int u, int p) {
    bool win = false;
    for (auto v : G[u]) {
        if (v != p) {
            if (!Win(v, u)) win = true;
        }
    }
    return win;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> n >> t;

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[v].push_back(u);
        G[u].push_back(v);
    }

    cin >> root;
    cout << (Win(root, 0) ? "Ron\n" : "Hermione\n");
    
    return 0;
} 