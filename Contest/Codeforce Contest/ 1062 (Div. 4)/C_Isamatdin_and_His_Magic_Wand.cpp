// Created on: 2025-10-28 20:41
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;

    bool o = false, e = false;
    vector<int> A(n);
    
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        o |= A[i] & 1;
        e |= !(A[i] & 1);
    }
    
    if (o && e) {
        sort(A.begin(), A.end());    
    }

    for (auto x : A) {
        cout << x << " ";
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 