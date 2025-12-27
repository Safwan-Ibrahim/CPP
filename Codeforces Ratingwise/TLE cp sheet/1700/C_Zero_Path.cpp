// Created on: 2025-07-05 03:40
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1007;
int n, m, A[nn][nn], Ans1[nn][nn], Ans2[nn][nn];

int min_cost(int i, int j) {
    if (i == n && j == m) return A[i][j];
    if (i > n || j > m) return 1e9;
    int &ans = Ans1[i][j];
    if (ans != -1e9) return ans;
    ans = A[i][j];
    ans += min(min_cost(i + 1, j), min_cost(i, j + 1));
    return ans;
}

int max_cost(int i, int j) {
    if (i == n && j == m) return A[i][j];
    if (i > n || j > m) return -1e9;
    int &ans = Ans2[i][j];
    if (ans != -1e9) return ans;
    ans = A[i][j];
    ans += max(max_cost(i + 1, j), max_cost(i, j + 1));
    return ans;
}

void Try() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> A[i][j];
        }
    }    
    
    if ((n + m - 1) % 2 == 1) {
        cout << "NO\n"; return;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            Ans2[i][j] = Ans1[i][j] = -1e9;
        }
    }
    if (min_cost(1, 1) <= 0 && max_cost(1, 1) >= 0) {
        cout << "YES\n";
    }
    else cout << "NO\n";
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 