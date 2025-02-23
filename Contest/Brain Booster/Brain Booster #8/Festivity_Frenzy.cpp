// Created on: 2025-02-17 20:37
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    int max_large = n / 500;
    int rest = n - max_large * 500;
    int max_small = rest / 5;

    cout << max_large * 1000 + max_small * 5 << endl;
    
    return 0;
} 