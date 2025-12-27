// Created on: 2025-12-27 08:22
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, A[nn], Ss[nn];  // ss = substree size
ll Cost[2][nn], Ans[nn];
vector<int> G[nn];

void dfs1(int u, int p) {
    Ss[u] = 1;
    for (auto v : G[u]) {
        if (v != p) {
            dfs1(v, u);
            Ss[u] += Ss[v];
        }
    }
}

void dfs2(int u, int p, int k) {
    int val = 1 << k; // val = value
    int bit = (A[u] >> k) & 1;
    Cost[bit ^ 1][u] = 1LL * Ss[u] * val;
    
    for (auto v : G[u]) {
        if (v != p) {
            dfs2(v, u, k);

            Cost[bit ^ 1][u] += Cost[bit ^ 1][v];
            Cost[bit][u] += Cost[bit][v];
            
            int bit_c = (A[v] >> k) & 1; // bit of child
            if (bit_c == bit) {
                Cost[bit ^ 1][u] -= 1LL * Ss[v] * val;
            }
            else {
                Cost[bit ^ 1][u] += 1LL * Ss[v] * val;
            }
        }
    }
}

vector<ll> cost(2, 0); 
vector<ll> pcost(2, 0); 

void dfs3(int u, int p, int k) {
    int val = 1 << k; // val = value
    int bit = (A[u] >> k) & 1;
    int bit_p = (A[p] >> k) & 1;
    
    pcost[0] = Cost[0][p], pcost[1] = Cost[1][p];
    
    pcost[bit_p ^ 1] -= 1LL * Ss[u] * val;
    
    pcost[bit_p ^ 1] -= Cost[bit_p ^ 1][u];
    pcost[bit_p] -= Cost[bit_p][u];
    
    if (bit == bit_p) {
        pcost[bit_p ^ 1] += 1LL * Ss[u] * val;
    }
    else {
        pcost[bit_p ^ 1] -= 1LL * Ss[u] * val;
    }
    

    int ss = n;
    
    cost[bit] = 0;
    cost[bit ^ 1] = 1LL * ss * val;
    for (auto v : G[u]) {
        if (v != p) {
            cost[bit ^ 1] += Cost[bit ^ 1][v];
            cost[bit] += Cost[bit][v];
            
            
            int bit_c = (A[v] >> k) & 1; // bit of child
            if (bit_c == bit) {
                cost[bit ^ 1] -= 1LL * Ss[v] * val;
            }
            else {
                cost[bit ^ 1] += 1LL * Ss[v] * val;
            }
        }
    }
    
    if (u != 1) {
        cost[bit ^ 1] += pcost[bit ^ 1];
        cost[bit] += pcost[bit];
    
        if (bit_p == bit) {
            cost[bit ^ 1] -= 1LL * (n - Ss[u]) * val;
        }
        else {
            cost[bit ^ 1] += 1LL * (n - Ss[u]) * val;
        }
        
    }
    
    Ans[u] += min(cost[0], cost[1]);
    Cost[0][u] = cost[0], Cost[1][u] = cost[1];

    for (auto v : G[u]) {
        if (v != p) {
            dfs3(v, u, k);
        }
    }
}

void Try() {
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs1(1, 0);

    for (int k = 0; k < 20; k++) {

        for (int i = 1; i <= n; i++) {
            Cost[0][i] = Cost[1][i] = 0;
        }

        dfs2(1, 0, k);
        dfs3(1, 0, k);
    }

    for (int i = 1; i <= n; i++) {
        cout << Ans[i] << " ";

        G[i].clear();
        Ss[i] = 0;
        Ans[i] = 0;
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


