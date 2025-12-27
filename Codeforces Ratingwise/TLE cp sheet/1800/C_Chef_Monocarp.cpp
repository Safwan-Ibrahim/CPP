// Created on: 2025-11-20 12:59
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 207;
int n, A[nn], Ans[nn][2 * nn];

int min_cost(int i, int step) {
    if (i > n) return 0;

    int &ans = Ans[i][step];
    if (ans != -1) return ans;

    ans = 1e9;
    for (int j = step + 1; j - step - 1 <= n + 1 && j <= 2 * n + 2; j++) {
        ans = min(ans, abs(A[i] - step) + min_cost(i + 1, j));
    }

    return ans;
}

void Try() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    sort(A + 1, A + n + 1);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 2 * n + 2; j++) {
            Ans[i][j] = -1;
        }
    }

    int mn = 1e9;
    for (int i = 1; i <= n; i++) {
        mn = min(mn, min_cost(1, i));
    }

    cout << mn << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 