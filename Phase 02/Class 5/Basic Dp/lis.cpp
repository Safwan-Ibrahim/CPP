// Created on: 2025-03-23 01:31
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e3 + 8;
int n, A[N];

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    vector<int>Lis(n + 1);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        Lis[i] = 1;
        for (int j = 1; j < i; j++) {
            if (A[j] < A[i]) {
                Lis[i] = max(Lis[j] + 1, Lis[i]);
            }
        }
        mx = max(mx, Lis[i]);
    }

    cout << mx << endl;

    return 0;
} 