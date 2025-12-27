// Created on: 2025-05-14 02:22
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 8;
vector<int> G[nn];
map<pair<int, int>, int>Mp;
int n;

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        if (x > y) swap(x, y);
        Mp[{x, y}] = i;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    vector<int> Ans(n + 5, -1);
    int num = 0;
    for (int i = 1; i <= n; i++) {
        if (G[i].size() == 1) {
            int x = i, y = G[i].back();
            if (x > y) swap(x, y);
            int path = Mp[{x, y}];
            if (Ans[path] == -1) {
                Ans[path] = num++;
            }
        }
    }

    for (int i = 1; i < n; i++) {
        cout << (Ans[i] != -1 ? Ans[i] : num++) << endl;
    }
    cout << endl;
    
    return 0;
} 