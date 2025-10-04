// Created on: 2025-09-24 01:46
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

struct DSU {
    vector<int> Par, Rank, Size;
    int c;

    DSU(int n) : Par(n + 1), Rank(n + 1, 0), Size(n + 1, 1), c(n) {
        for (int i = 1; i <= n; i++) Par[i] = i;;
    }

    int find(int v) {
        if (Par[v] == v) return v;
        else return Par[v] = find(Par[v]); // Path compression
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
        if (a == b) return; // Already in the same component
        c--; // Decrease component count
        if (Rank[a] > Rank[b]) swap(a, b); // Union by rank
        Par[a] = b;
        Size[b] += Size[a];
        if (Rank[a] == Rank[b]) Rank[b]++;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);



    return 0;
} 