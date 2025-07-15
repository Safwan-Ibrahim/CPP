// Created on: 2025-07-09 16:46
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    string A, B; cin >> A >> B;
    if (A != B) {
        cout << max(A.size(), B.size()) << endl; return 0;
    }
    cout << -1 << endl; 
    return 0;
} 