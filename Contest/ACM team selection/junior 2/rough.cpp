// Created on: 2025-08-02 16:09
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    o_set<pair<int, int>>St;
    St.insert({1, 1}); St.insert({1, 2});
    cout << St.order_of_key({2, 0});
    return 0;
} 