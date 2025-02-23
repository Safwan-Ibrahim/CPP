// Created on: 2025-02-21 00:10
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1005;
vector<int> G[N];
bool Vs[N];
int Money[N];
int money_of_group, num_of_person;

void dfs(int u) {
    Vs[u] = true;
    num_of_person++;
    money_of_group += Money[u];
    for (auto x : G[u]) {
        if (!Vs[x]) {
            dfs(x);
        }
    }
}

void Try() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> Money[i];
        G[i].clear();
        Vs[i] = 0;
    }

    while(m--) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int total = 0;
    for (int i = 1; i <= n; i++) {
        total += Money[i];
    }

    if (total % n != 0) {
        cout << "No\n"; return;
    }

    int per = total / n;
    for (int i = 1; i <= n; i++) {
        if (!Vs[i]) {
            money_of_group = num_of_person = 0;
            dfs(i);
            if (num_of_person * per != money_of_group) {
                cout << "No\n";
                return;
            }
        }
    }

    cout << "Yes\n";
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        Try();
    }
    return 0;
} 