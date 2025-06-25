// Created on: 2025-05-31 21:55
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 5e3 + 18;
int n, A[nn], gcd_, Ans[nn][nn];

int min_step(int i, int g) {
    if (i == n + 1) {
        if (g == gcd_) return 0;
        else return 2e9;
    }
    int &ans = Ans[i][g];
    if (ans != -1) return ans;
    ans = min_step(i + 1, g);
    ans = min(ans, 1 + min_step(i + 1, gcd(g, A[i])));
    return ans;
}

void Try() {
    cin >> n;
    gcd_ = 0;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        gcd_ = gcd(gcd_, A[i]);
    }

    int count_gcd = 0; int mx = -1;
    for (int i = 1; i <= n; i++) {
        if (A[i] == gcd_) {
            count_gcd++;
        }
        mx = max(mx, A[i]);
    }

    if (count_gcd) {
        cout << n - count_gcd << endl; return;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= mx; j++) {
            Ans[i][j] = -1;
        }
    }

    int need = min_step(1, 0) - 1;
    cout << n - 1 + need << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 