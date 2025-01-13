// Created on: 2025-01-02 17:10
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    vector<int>ans;
    if (n % 2 == 0) {
        ans.assign(n / 2, 2);
    }
    else {
        ans.assign((n - 3) / 2, 2);
        ans.push_back(3);
    }
    cout << ans.size() << endl;
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
} 