// Created on: 2025-01-21 17:49
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    int N; cin >> N;

    vector<int>A;
    int min_pos = INT_MAX, zero = 0;
    bool got = false;
    for (int i = 1; i <= N; i++) {
        int x; cin >> x;
        if (x <= 0) {
            A.push_back(x);
        }
        else {
            got = true;
            min_pos = min(min_pos, x);
        }
    }

    sort(A.begin(), A.end());
    int ans = A.size() + got;
    for (int i = 0; i + 1 < A.size(); i++) {
        if (abs(A[i + 1] - A[i]) < min_pos && got) {
            ans--;
            break;
        }
    }

    cout << ans << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T = 1; cin >> T;
    for (int i = 1; i <= T; i++) {
        solve();
    }
    return 0;
} 