// Created on: 2025-05-06 06:20
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 15;
int n, A[nn], Ans[nn];

int min_op(int i) {
    if (i == n + 1) {
        return 0;
    }
    int &ans = Ans[i];
    if (ans != -1) {
        return ans;
    }
    ans = 1 + min_op(i + 1);
    if (A[i] <= n - i) {
        ans = min(ans, min_op(i + A[i] + 1));
    }
    return ans;
}

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    memset(Ans, -1, (n + 5) * sizeof (int));
    cout << min_op(1) << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 