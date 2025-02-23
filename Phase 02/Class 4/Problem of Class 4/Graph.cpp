// Created on: 2025-02-13 16:18
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 105;
int G[N][N];

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int v; cin >> v;
        int k; cin >> k;
        for (int j = 1; j <= k; j++) {
            int x; cin >> x;
            G[v][x] = 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << G[i][j];
            if (j != n) {
                cout << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
} 