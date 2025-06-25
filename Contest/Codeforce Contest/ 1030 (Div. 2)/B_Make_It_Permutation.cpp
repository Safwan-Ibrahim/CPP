// Created on: 2025-06-12 21:50
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    vector<array<int, 3>>Ans;
    for (int i = 1; i <= n; i++) {  
        if (i > 1) {
            Ans.push_back({i, 1, i});
        }
        if (n - i > 1) {
            Ans.push_back({i, i + 1, n});
        }
    }
    cout << Ans.size() << endl;
    for (auto vec : Ans) {
        for (auto x : vec) {
            cout << x << " ";
        }
        cout << endl;
    }
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 