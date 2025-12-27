// Created on: 2025-12-23 21:36
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;

    int s = (1 << n);
    vector<vector<int>> V(n + 1); // value
    
    for (int i = 0; i < s; i++) {
        int mx_bit = 0;
        for (int k = 1; k <= n; k++) {
            int ck = (1 << k) - 1;
            if ((ck & i) != ck) break;
            mx_bit = ck;
        }
        
        while (mx_bit) {
            V[__builtin_popcount(mx_bit)].push_back(i);
            mx_bit >>= 1;
        }
    }
    
    vector<bool> Vs(s + 1, 0);
    vector<int> Ans;
    for (int i = n; i >= 1; i--) {
        for (auto x : V[i]) {
            if (!Vs[x]) {
                Ans.push_back(x);
                Vs[x] = 1;
            }
        }
    }

    for (int i = 0; i < s; i++) {
        if (!Vs[i]) {
            Ans.push_back(i);
            Vs[i] = 1;
        }
    }

    for (auto x : Ans) {
        cout << x << " ";
    }
    cout << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 