// Created on: 2025-01-22 18:20
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    int N, L, R; cin >> N >> L >> R;

    vector<int>A, B, C;

    for (int i = 1; i <= N; i++) {
        int x; cin >> x;
        if (i < L) {
            A.push_back(x);
        }
        else if (i > R) {
            C.push_back(x);
        }
        else {
            B.push_back(x);
        }
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    
    ll ans = accumulate(B.begin(), B.end(), 0LL);
    ll SC = 0, SA = 0;

    int P = (int)B.size() - 1;
    for (int i = 0; i < C.size(); i++) {
        if (B[P] > C[i] && P >= 0) {
            SC += (B[P] - C[i]);
            P--;
        }
        else {
            break;
        }
    }

    P = (int)B.size() - 1;
    for (int i = 0; i < A.size(); i++) {
        if (B[P] > A[i] && P >= 0) {
            SA += (B[P] - A[i]);
            P--;
        }
        else {
            break;
        }
    }

    cout << ans - max(SA, SC) << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T = 1; cin >> T;
    for (int i = 1; i <= T; i++) {
        solve();
    }
    return 0;
} 