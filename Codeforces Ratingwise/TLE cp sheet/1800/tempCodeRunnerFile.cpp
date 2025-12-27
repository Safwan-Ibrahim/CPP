// Created on: 2025-11-17 16:44
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int U[nn], V[nn], W[nn];
vector<pair<int, int>> G[nn];

struct DSU {
    vector<int> Par, Size;
    vector<vector<int>> Cc;
    int c;
    
    DSU(int n) : Par(n + 1), Size(n + 1, 1), c(n), Cc(n + 1) {
        for (int i = 1; i <= n; i++) {
            Par[i] = i;;
            Cc[i].push_back(i);
        }
    }

    int find(int v) {
        if (Par[v] == v) return v;
        else return Par[v] = find(Par[v]);
    }

    bool same(int a, int b) {
        return find(a) == find(b);
    }

    int get_size(int v) {
        return Size[find(v)];
    }

    int count() {
        return c;
    }

    void merge(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return;
        c--; 
        if (Size[a] > Size[b]) swap(a, b); 
        for (auto x : Cc[a]) {
            Cc[b].push_back(x);
        }
        Cc[a].clear();
        Par[a] = b;
        Size[b] += Size[a];

    }
};

void Try() {
    int n, m, k; cin >> n >> m >> k;
    
    vector<int> A;
    for (int i = 1; i <= m; i++) {
        cin >> U[i] >> V[i] >> W[i];
        A.push_back(W[i]);
    }
    
    sort(A.begin(), A.end());

    DSU D(n);
    for (int i = 1; i <= m; i++) {
        if (W[i] <= k) {
            D.merge(U[i], V[i]);
        }
    }

    if (D.count() == 1) {
        int ans = 1e9;
        auto it = lower_bound(A.begin(), A.end(), k);

        if (it != A.end()) ans = min(ans, *it - k);
        if (it != A.begin()) {
            it--; ans = min(ans, k - *it);
        }

        cout << ans << endl; return;
    }

    
    vector<array<int, 3>> E;
    for (int i = 1; i <= m; i++) {
        int u = U[i], v = V[i], w = W[i];
        if (!D.same(u, v)) {
            E.push_back({w, u, v});
        }
    }
    
    ll ans = 0;
    sort(E.begin(), E.end());

    for (auto [u, v, w] : E) {
        if (!D.same(u, v)) {
            D.merge(u, v);
            ans += w - k;
        }
    }

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 