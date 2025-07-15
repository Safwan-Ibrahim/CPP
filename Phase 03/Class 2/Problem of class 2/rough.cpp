// Created on: 2025-07-10 20:33
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long get_rand(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rng);
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int r = get_rand(10, 20);
    cout << r << endl;
    return 0;
} 