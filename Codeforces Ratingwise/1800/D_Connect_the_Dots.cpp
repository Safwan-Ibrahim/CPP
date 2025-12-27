// Created on: 2025-12-04 10:42
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int n, m;

struct DSU {
    vector<int> Par, Size;
    int c;
    
    DSU(int n) : Par(n + 1), Size(n + 1, 1), c(n) {
        for (int i = 0; i < n; i++) Par[i] = i;;
    }

    void build(int n) {
        Par = vector<int> (n), Size = vector<int> (n, 1);
        c = n;
        for (int i = 0; i < n; i++) Par[i] = i;
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

DSU DS(n);

void add_points(int d, vector<pair<int, int>> &A) {
    
    vector<vector<int>> D(d, vector<int> (n / d + 5, 0));
    for (auto [a, k] : A) {
        int s = a % d;
        D[s][a / d]++;
        D[s][a / d + k]--; 
    }
    
    for (int i = 0; i < d; i++) {

        int sum = 0;
        for (int j = 0; j <= n / d; j++) {
            sum += D[i][j];
            D[i][j] = sum;

            if (D[i][j] && 1LL * (j + 1) * d + i < n) {
                DS.merge(j * d + i, (j + 1) * d + i);
            }
        }
    }

}

void Try() {
    cin >> n >> m;

    vector<pair<int, int>> Q[11];
    
    for (int i = 1; i <= m; i++) {
        int a, d, k; cin >> a >> d >> k;
        Q[d].push_back({a - 1, k});
    }

    DS.build(n);

    for (int i = 1; i <= 10; i++) {
        if (Q[i].size()) add_points(i, Q[i]);
    }

    cout << DS.count() << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 