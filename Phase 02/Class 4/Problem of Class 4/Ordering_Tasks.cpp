// Created on: 2025-03-13 23:23
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 105;
vector<int>G[N];
int n, m, Indeg[N]; // rem to clear all

void Try() {
    while (m--) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        Indeg[v]++;
    }

    vector<int>Ans;
    stack<int>St;

    for (int i = 1; i <= n; i++) {
        if (Indeg[i] == 0) {
            St.push(i);
        }
    }

    while(Ans.size() < n) {
        int u = St.top();
        St.pop();
        Ans.push_back(u);

        for (auto v : G[u]) {
            Indeg[v]--;
            if (Indeg[v] == 0) {
                St.push(v);
            }
        }
    }

    for (auto x : Ans) {
        cout << x << " ";
    }
    cout << endl;

    for (int i = 1; i <= n; i++) {
        G[i].clear();
    }
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    while(cin >> n >> m && (m != 0 || n != 0)) {
        Try();
    }
    return 0;
} 