// Created on: 2025-11-30 12:14
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

struct DSU {
    vector<int> Par, Size;
    int c;
    
    DSU(int n) : Par(n + 1), Size(n + 1, 1), c(n) {
        for (int i = 1; i <= n; i++) Par[i] = i;;
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
        Par[a] = b;
        Size[b] += Size[a];
    }
};

void Try() {
    int n, m, k; cin >> n >> m >> k;
    
    DSU D(n);
    vector<array<int, 3>> E;
    set<int> S;
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        S.insert(w);
        if (w <= k) {
            D.merge(u, v);
        }
        else {
            E.push_back({w, u, v});
        }
    }
    
    if (D.count() == 1) {
        int ans = 1e9;

        auto it = S.lower_bound(k);
        if (it != S.end()) {
            ans = min(ans, abs(k - *it));
        }
        if (it != S.begin()) {
            it--;
            ans = min(ans, abs(k - *it));
        }

        cout << ans << endl;
        return;
    }

    sort(E.begin(), E.end());
    ll ans = 0;
    for (auto [w, u, v] : E) {
        if (!D.same(u, v)) {
            ans += w - k;
            D.merge(u, v);
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