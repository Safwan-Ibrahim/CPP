// Created on: 2025-08-10 20:44
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    vector<int>Ans;
    for (int i = 1; i <= n; i++) {
        if (i & 1) {
            Ans.push_back(-1);
        }
        else Ans.push_back(3);
    }
    
    if (n % 2 == 0) {
        Ans.pop_back();
        Ans.push_back(2);
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