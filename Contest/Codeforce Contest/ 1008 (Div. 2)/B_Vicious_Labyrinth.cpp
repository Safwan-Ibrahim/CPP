// Created on: 2025-03-10 21:21
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, k; cin >> n >> k;
    vector<int>Ans;
    if (k & 1) {
        for (int i = 1; i <= n; i++) {
            if (i != n) {
                Ans.push_back(n);
            }
            else {
                Ans.push_back(n - 1);
            }
        }
    }
    else {
        for (int i = 1; i <= n; i++) {
            if (i != n - 1) {
                Ans.push_back(n - 1);
            }
            else {
                Ans.push_back(n);
            }
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