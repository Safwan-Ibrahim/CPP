// Created on: 2025-07-12 02:31
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 17;
int n, A[nn];

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }    
    
    sort(A + 1, A + n + 1);
    for (int i = 3; i <= n; i++) {
        if (A[i - 2] + A[i - 1] > A[i]) {
            cout << "YES\n"; return 0;
        }
    }

    cout << "NO\n";
    
    return 0;
} 