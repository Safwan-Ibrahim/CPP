// Created on: 2025-07-29 18:35
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, A[nn], In[nn];
vector<int> G[nn];  

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= n; i++) {
        G[i].push_back(A[i]);
        In[A[i]]++;
    }

    queue<pair<int, int>>Q;
    for (int i = 1; i <= n; i++) {
        if (!In[i]) Q.push({i, 0});
    }

    vector<int>Dis(n + 1, 0); int mx = 0;
    while(Q.size()) {
        auto [u, p] = Q.front();    
        Q.pop();
        Dis[u] = Dis[p] + 1; mx = max(mx, Dis[u]);
        for (auto v : G[u]) {
            In[v]--;
            if (!In[v]) {
                Q.push({v, u});
            }
        }
    }

    cout << mx + 2 << endl;

    for (int i = 1; i <= n; i++) {
        G[i].clear(); In[i] = 0;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 