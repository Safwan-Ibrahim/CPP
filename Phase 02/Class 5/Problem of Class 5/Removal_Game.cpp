// Created on: 2025-04-06 12:29
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 5e3 + 8;
int n, A[nn];
ll Ans[2][nn][nn];
bool Vs[2][nn][nn];

ll dif(int i, int j, bool last_a) {
    if (i > j) {
        return 0;
    }
    if (Vs[last_a][i][j]) {
        return Ans[last_a][i][j];
    }
    if (!last_a) {
        ll ans = A[i] + dif(i + 1, j, true);
        ans = max(ans, A[j] + dif(i, j - 1, true));
        Vs[last_a][i][j] = true;
        return Ans[last_a][i][j] = ans;
    }
    if (last_a) {
        ll ans = -A[i] + dif(i + 1, j, false);
        ans = min(ans, -A[j] + dif(i, j - 1, false));
        Vs[last_a][i][j] = true;
        return Ans[last_a][i][j] = ans;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        sum += A[i];
    }

    ll x_m_y = dif(1, n, false);
    ll x_p_y = sum;
    cout << (x_p_y + x_m_y) / 2 << endl;

    return 0;
} 