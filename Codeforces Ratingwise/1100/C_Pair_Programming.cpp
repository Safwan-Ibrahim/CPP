// Created on: 2025-01-21 14:41
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    int K, N, M; cin >> K >> N >> M;

    int A[N + 1], B[M + 1];
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= M; i++) {
        cin >> B[i];
    }

    int P1 = 1, P2 = 1;  

    vector<int>ans;
    for (int i = 1; i <= N + M; i++) {
        if (P1 <= N && A[P1] <= K) {
            if (A[P1] == 0) {
                K++;
            }
            ans.push_back(A[P1++]);
        }
        else if (P2 <= M && B[P2] <= K) {
            if (B[P2] == 0) {
                K++;
            }
            ans.push_back(B[P2++]);
        }
        else {
            cout << -1 << endl; 
            return;
        }
    }

    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
} 