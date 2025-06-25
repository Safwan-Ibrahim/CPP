// Created on: 2025-04-26 13:48
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
pair<int, int> A[nn];

void Try() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int st, end; cin >> st >> end;
        A[i] = {end, st};
    }

    sort(A + 1, A + n + 1);
    ll ans = 0;
    o_set<int>St;
    for (int i = 1; i <= n; i++) {
        int st = A[i].second;
        ans += St.size() - St.order_of_key(st + 1);
        St.insert(st);
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