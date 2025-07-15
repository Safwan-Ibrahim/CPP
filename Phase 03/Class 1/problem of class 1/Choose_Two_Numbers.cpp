// Created on: 2025-07-09 19:33
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int get_max() {
    int n; cin >> n;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        mx = max(mx, x);
    }
    return mx;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout << get_max() << " " << get_max() << endl;
    return 0;
} 