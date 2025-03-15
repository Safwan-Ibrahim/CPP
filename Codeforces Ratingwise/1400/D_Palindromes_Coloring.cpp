// Created on: 2025-02-23 20:49
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, k; cin >> n >> k;
    map<char, int>Mp;
    
    int p = 0; 
    for (int i = 1; i <= n; i++) {
        char c; cin >> c;
        Mp[c]++;
        if (Mp[c] == 2) {
            Mp[c] -= 2;
            p++;
        }
    }   
    
    int ex = 0;
    for (auto [x, y] : Mp) {
        if (y > 0) {
            ex++;
        }
    }

    ex += p % k * 2;

    int mx = p / k * 2;
    mx += ex >= k;
    
    cout << mx << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 