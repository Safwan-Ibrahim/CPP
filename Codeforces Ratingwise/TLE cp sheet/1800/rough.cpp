// Created on: 2025-11-19 22:26
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

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cout << 1LL * 4e10 / 64 << endl; 
    
    return 0;
} 