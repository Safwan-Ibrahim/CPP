// Created on: 2025-01-21 16:53
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    int N; cin >> N;
    
    int A[N + 1];
    set<int>DA;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        DA.insert(i);
    }

    for (int i = 1; i <= N; i++) {
        while (DA.find(A[i]) == DA.end() && A[i] > 0) {
            A[i] /= 2;
        }
        if (A[i] != 0) {
            DA.erase(A[i]);
        }
        else {
            cout << "NO\n"; 
            return;
        }
    }
    
    cout << "YES\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T = 1; cin >> T;
    for (int i = 1; i <= T; i++) {
        solve();
    }
    return 0;
} 