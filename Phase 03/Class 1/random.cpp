// Created on: 2025-07-09 15:24
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
    
    for (int i = 1; i <= 10; i++) {
        cout << get_rand(10, 100) << endl;
    }
    
    return 0;
} 