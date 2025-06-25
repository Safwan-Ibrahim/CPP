// Created on: 2025-06-03 07:18
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 18;
int n, A[nn];
vector<int> G[nn];
set<pair<int, int>>St;

void dfs(int u) {
    St.erase({A[u], u});
    int sz = G[u].size();
    if (sz == 2) {
        int a = G[u].front(), b = G[u].back();
        G[a].erase(find(G[a].begin(), G[a].end(), u));
        G[b].erase(find(G[b].begin(), G[b].end(), u));
        G[a].push_back(b), G[b].push_back(a);
        if (A[a] >= A[b] && A[a] <= A[u]) {
            dfs(a); return;
        }
        if (A[b] >= A[a] && A[b] <= A[u]) {
            dfs(b); return;
        }
    }
    else if (sz == 1) {
        int a = G[u].front();
        G[a].erase(find(G[a].begin(), G[a].end(), u));
        if (A[a] <= A[u]) {
            dfs(a); return;
        }
    }

}

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    for (int i = 1; i < n; i++) {
        G[i].push_back(i + 1);
        G[i + 1].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        St.insert({A[i], i});
    }

    int ans = 0;
    while(St.size()) {
        ans++;
        auto it = St.rbegin();
        dfs(it->second);
    }

    cout << ans << endl;
    for (int i = 1; i <= n; i++) {
        G[i].clear();
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