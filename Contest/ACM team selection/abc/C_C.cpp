// Created on: 2025-11-07 10:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;

    int cnt1 = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        sum ^= x;
        cnt1 += (x == 1);
    }
    cerr<<sum<<' '<<cnt1<<endl;
    cout << (sum ? "Mrinalini\n" : "Kadambari\n");
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 