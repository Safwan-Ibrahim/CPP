// Created on: 2025-07-12 01:49
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    vector<int>A(n);
    for (auto &x : A) {
        cin >> x;
    }

    bool odd = false, even = false;
    for (auto x : A) {
        if (x & 1) odd = true;
        else even = true;
    }

    if (odd && even) {
        sort(A.begin(), A.end());
    }

    for (auto x : A) {
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
} 