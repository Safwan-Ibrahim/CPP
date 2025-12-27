// Created on: 2025-12-26 04:45
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int inf = 1e9 + 7;
int n; 
vector<int> A, B;

int add() {
    int ans = 0;

    int mn = inf;
    for (int i = 0; i < n; i++) {
        ans = max(ans, min(A[i], B[i]) - mn << 1);
        mn = min(mn, max(A[i], B[i]));
    }

    return ans;
}

void Try() {
    cin >> n;

    A.resize(n), B.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }
    
    int mx = add();

    reverse(A.begin(), A.end()), reverse(B.begin(), B.end());
    mx = max(mx, add());

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(A[i] - B[i]);
    }

    cout << ans + mx << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 