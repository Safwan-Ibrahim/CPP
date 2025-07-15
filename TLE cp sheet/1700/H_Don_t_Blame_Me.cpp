// Created on: 2025-06-30 20:39
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17, mod = 1e9 + 7;
int n, k, A[nn], Ans[2][64][nn];

int way(int i, int mask, bool taken) {
    if (i == n + 1) {
        return taken && __builtin_popcount(mask) == k;
    }
    int &ans = Ans[taken][mask][i];
    if (ans != -1) return ans;
    ans = 0;
    ans += way(i + 1, mask & A[i], true);
    ans += way(i + 1, mask, taken);
    if (ans >= mod) ans -= mod;
    return ans;
}

void Try() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int mask = 0; mask <= 63; mask++) {
            Ans[0][mask][i] = Ans[1][mask][i] = -1;
        }
    }
    cout << way(1, 63, false) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 