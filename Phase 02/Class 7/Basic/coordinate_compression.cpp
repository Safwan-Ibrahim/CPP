// Created on: 2025-04-16 02:41
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n; cin >> n;
    int A[n + 1];
    set<int>St;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        St.insert(A[i]);
    }

    map<int, int>Mp;
    int id = 0;
    for (auto x : St) {
        Mp[x] = ++id;
    }

    for (int i = 1; i <= n; i++) {
        A[i] = Mp[A[i]];
    }
    
    return 0;
} 