// Created on: 2025-06-24 15:38
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1007;
const ll inf = 1e15;
int n, A[nn], B[nn], M[nn][nn];
ll Ans_row[2][nn], Ans_col[2][nn];

ll min_cost1(int col, bool prev_hired) {
    if (col == n + 1) return 0;
    ll &ans = Ans_row[prev_hired][col];
    if (ans != -1) return ans;
    ans = inf;
    bool ok_with_hire = true, ok = true;
    for (int row = 1; row <= n; row++) {
        if (M[row][col - 1] + prev_hired == M[row][col]) ok = false;
        if (M[row][col - 1] + prev_hired == M[row][col] + 1) ok_with_hire = false;
    }
    if (ok_with_hire) {
        ans = min(ans, B[col] + min_cost1(col + 1, true));
    }
    if (ok) {
        ans = min(ans, min_cost1(col + 1, false));
    }
    return ans;
}

ll min_cost_2(int row, bool prev_hired) {
    if (row == n + 1) return 0;
    ll &ans = Ans_col[prev_hired][row];
    if (ans != -1) return ans;
    ans = inf;
    bool ok_with_hire = true, ok = true;
    for (int col = 1; col <= n; col++) {
        if (M[row - 1][col] + prev_hired == M[row][col]) ok = false;
        if (M[row - 1][col] + prev_hired == M[row][col] + 1) ok_with_hire = false;
    }
    if (ok_with_hire) {
        ans = min(ans, A[row] + min_cost_2(row + 1, true));
    }
    if (ok) {
        ans = min(ans, min_cost_2(row + 1, false));
    }
    return ans;
}

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> M[i][j];
        }
    }
    
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> B[i];
    }

    for (int i = 1; i <= n; i++) {
        Ans_col[0][i] = Ans_row[0][i] = Ans_col[1][i] = Ans_row[1][i] = -1;
    }

    ll ans = min_cost1(1, 0) + min_cost_2(1, 0);
    if (ans >= inf) cout << -1 << endl;
    else cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 