// Created on: 2025-04-24 11:45
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    
    int n; cin >> n;
    int cur = 1;
    vector<int> res;
    while (n--) {
        int l, r; cin >> l >> r;

        if(l <= cur && r >= cur) res.push_back(cur++);
        else if(cur < l) {
            cur = l;
            res.push_back(cur++);
        }
        else res.push_back(0);
    }
    
    for(auto e : res) cout << e << " "; cout << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 