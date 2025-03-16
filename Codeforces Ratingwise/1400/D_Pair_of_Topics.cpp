// Created on: 2025-03-16 19:22
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'


int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n; cin >> n;
    vector<int>A(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        A[i] -= x;
    }

    sort(A.begin() + 1, A.end());
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int id = A.end() - upper_bound(A.begin() + i + 1, A.end(), 0 - A[i]);
        ans += id;
    }

    cout << ans << endl;
    
    return 0;
} 