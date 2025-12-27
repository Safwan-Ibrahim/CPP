// Created on: 2025-11-12 11:39
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
vector<int> G[nn];
int n; bool Vs[nn];

vector<int> A;
void dfs(int u) {
    A.push_back(u);
    Vs[u] = true;
    if (!Vs[G[u].front()]) dfs(G[u].front());
}

bool pos() {
    sort(A.begin(), A.end());
    bool ok = false;
    for (int i = 0; i + 1 < A.size(); i++) {
        if (A[i] + 1 == A[i + 1]) ok = true;
    }
    A.clear();
    return ok;
}

void Try() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        G[i].push_back(x);
    }

    int comp = 0; bool less = 0;
    for (int i = 1; i <= n; i++) {
        if (!Vs[i]) {
            comp++;
            dfs(i);
            less |= pos();
        }
    }

    cout << n - comp + (less ? -1 : 1) << endl;

    for (int i = 1; i <= n; i++) {
        G[i].clear();
        Vs[i] = 0;
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