// Created on: 2025-10-28 20:37
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    string A, B; cin >> A >> B;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    cout << (A == B ? "YES\n" : "NO\n"); 
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 