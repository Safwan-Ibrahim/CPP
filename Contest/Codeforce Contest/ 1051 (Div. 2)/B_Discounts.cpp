// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, m, A[nn], B[nn];

void Try() {
    cin >> n >> m;

    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        sum += A[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> B[i];
    }
    
    sort(A + 1, A + n + 1, greater<int>());
    sort(B + 1, B + m + 1);
    
    int last = 1;
    for (int i = 1; i <= m; i++) {
        last += B[i];
        if (last - 1 <= n) sum -= A[last - 1];
        else break;
    }

    cout << sum << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 