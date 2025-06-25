// Created on: 2025-05-30 14:14
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 8;
int n, k, z, A[nn], Ans[2][6][nn];

int max_score(int i, int step, int back, bool from_right) {
    if (step == -1) return 0;
    int &ans = Ans[from_right][back][i];
    if (ans != -1) return ans;
    ans = A[i] + max_score(i + 1, step - 1, back, false);
    if (!from_right && back && i > 1) {
        ans = max(ans, A[i] + max_score(i - 1, step - 1, back - 1, true));
    }
    return ans;
}

void Try() {
    cin >> n >> k >> z;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 5; j++) {
            Ans[0][j][i] = -1;
            Ans[1][j][i] = -1;
        }
    }

    cout << max_score(1, k, z, false) << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 