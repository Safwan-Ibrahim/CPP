// Created on: 2025-05-10 12:15
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 8;
int n, A[nn], Ans[2][nn];

int min_skip(int i, int p) {
    if (i > n) {
        return 0;
    }
    int &ans = Ans[p][i];
    if (ans != -1) {
        return ans;
    }
    int a = (p ? 0 : A[i]);
    int b = (p ? 0 : A[i + 1]);

    ans = a + min_skip(i + 1, p ^ 1);
    if (i + 1 <= n) {
        ans = min(ans, a + b + min_skip(i + 2, p ^ 1));
    }
    return ans;
}

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    for (int i = 1; i <= n; i++) {
        Ans[0][i] = Ans[1][i] = -1;
    }

    cout << min_skip(1, 0) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 