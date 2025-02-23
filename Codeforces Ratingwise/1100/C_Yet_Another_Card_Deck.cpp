// Created on: 2025-01-28 19:36
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 3e5 + 9;
int A[N], MP[55];

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    for (int i = n; i >= 1; i--) {
        MP[A[i]] = i;
    }

    while(q--) {
        int x; cin >> x;
        cout << MP[x] << " ";
        for (int i = 1; i <= 50; i++) {
            if (i == x) {
                continue;
            }
            if (MP[i] < MP[x]) {
                MP[i]++;
            }
        }
        MP[x] = 1;
    }
    
    return 0;
} 