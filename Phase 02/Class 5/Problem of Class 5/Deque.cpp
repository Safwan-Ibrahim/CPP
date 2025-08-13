// Created on: 2025-03-29 03:05
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 3e3 + 8;
int n, A[nn];
ll Ans[2][nn][nn];

ll dif(int i, int j, bool last_p1) {
    if (i > j) {
        return 0;
    }
    ll &ans = Ans[last_p1][i][j];
    if (ans != -1) {
        return ans;
    }
    if (!last_p1) {
        ans = A[i] + dif(i + 1, j, true);
        ans = max(ans, A[j] + dif(i, j - 1, true));
    }
    else {
        ans = dif(i + 1, j, false) - A[i];
        ans = min(dif(i, j - 1, false) - A[j], ans);
    }
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    memset(Ans, -1, sizeof Ans);
    cout << dif(1, n, false) << endl;

    return 0;
} 