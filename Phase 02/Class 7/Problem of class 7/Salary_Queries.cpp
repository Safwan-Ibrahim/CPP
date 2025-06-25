// Created on: 2025-04-16 19:10
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int nn = 2e5 + 8;
int n, A[nn];

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int q; cin >> n >> q;
    o_set<pair<int, int>>Os;
    int time = 0;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        Os.insert({A[i], ++time});
    }

    for (int i = 1; i <= q; i++) {
        char c; int l, r; cin >> c >> l >> r;
        if (c == '?') {
            auto up = Os.order_of_key({r, INT_MAX}) ;
            auto lo = Os.order_of_key({l, 0});
            cout << up - lo << endl;
        }
        else {
            int v = A[l];
            A[l] = r;
            Os.erase(Os.lower_bound({v, 0}));
            Os.insert({r, ++time});
        }
    }

    
    return 0;
} 