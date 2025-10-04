// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, k, A[nn];

void Try() {
    cin >> n >> k;
    
    set<int> St;
    int cnt = 0, have = 0;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        if (!St.count(A[i]) && A[i] < k) {
            St.insert(A[i]);
            have++;
        }
        if (A[i] == k) cnt++;
    }

    int need = k - have;
    cout << max(need, cnt) << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 