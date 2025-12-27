// Created on: 2025-11-10 11:45
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17, mod = 998244353;
int n, A[nn], Ans[nn][2][2][4];

int way(int i, int pp, int p, int taken) {
    if (i == n + 1) {
        return taken == 3;
    }

    int &ans = Ans[i][pp][p][taken];
    if (~ans) return ans;

    ans = way(i + 1, pp, p, taken);
    if (p == -1) {
        ans += way(i + 1, -1, A[i], min(3, taken + 1));
    }
    else if (pp == -1) {
        ans += way(i + 1, p, A[i], min(3, taken + 1));
    }
    else if ((pp + p + A[i]) % 2 == 0) { 
        ans += way(i + 1, p, A[i], min(3, taken + 1));
    }

    return ans %= mod;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        A[i] %= 2;
    }

    memset(Ans, -1, sizeof Ans);
    cout << way(1, -1, -1, 0) << endl;

    return 0;
} 