// Created on: 2025-04-05 15:30
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 8, M = 1e9 + 7;
int n, m, A[nn], Ans[nn][105];

int way(int i, int x) {
    if (i == n) {
        if (A[i] != 0 && x != A[i]) {
            return 0;
        }
        return 1;
    }
    if (A[i] != 0 && x != A[i]) {
        return 0;
    }
    int &ans = Ans[i][x];
    if (ans != -1) {
        return ans;
    }
    ans = 0;
    ans = (ans + way(i + 1, x)) % M;
    if (x + 1 <= m) {
        ans = (ans + way(i + 1, x + 1)) % M;
    }
    if (x != 1) {
        ans = (ans + way(i + 1, x - 1)) % M;
    }
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    memset(Ans, -1, sizeof Ans);
    if (A[1] != 0) {
        cout << way(1, A[1]) << endl;
    }
    else {
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            ans += way(1, i);
            ans %= M;
        }
        cout << ans << endl;
    }

    return 0;
} 