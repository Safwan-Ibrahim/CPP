// Created on: 2025-04-30 23:48
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
    
    o_set<int>Os;
    Os.insert(13);
    cout << (Os.order_of_key(14)) << endl;
    
    return 0;
} 