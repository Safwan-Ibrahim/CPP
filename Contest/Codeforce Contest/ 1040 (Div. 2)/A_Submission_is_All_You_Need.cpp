// Created on: 2025-07-31 20:39
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        sum += max(1, x);
    }
    
    cout << sum << endl;
}
 
int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 