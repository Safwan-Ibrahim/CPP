// Created on: 2025-07-13 17:36
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
    if (A[n] >= A[n - 1] + A[n - 2]) {
        cout << "NO\n"; return 0;
    } 

    cout << "YES\n";
    A[0] = A[n - 2];
    for (int i = 0; i <= n; i++) {
        if (i == n - 2) continue;
        cout << A[i] << " ";
    }
    cout << endl;
    
    return 0;
} 