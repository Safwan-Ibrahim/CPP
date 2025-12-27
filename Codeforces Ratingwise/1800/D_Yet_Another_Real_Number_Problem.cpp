// Created on: 2025-12-03 14:59
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17, mod = 1e9 + 7;
int n, A[nn], P2[nn], Ans[nn], Ps[nn];

ll power(int x, int n, ll m) {
    ll ans = 1 % m;
    while(n > 0) {
        if (n & 1) {
            ans = 1LL * ans * x % m;
        }
        n >>= 1;
        x = 1LL * x * x % m;
    }
    return ans;
}

bool cmp(int i, int p2, int self, int j) {
    if (self >= 32) {
        return 1;
    }

    if (A[i] <= 1LL * A[j] * power(2, self, 1e18)) {
        return 1;
    }

    return 0;
}

void Try() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    for (int i = 1; i <= n; i++) {
        int p2 = 0;
        while (A[i] % 2 == 0) {
            A[i] /= 2;
            p2++;
        }
        P2[i] = p2;
    }

    for (int i = 1; i <= n; i++) {
        Ps[i] = (Ps[i - 1] + A[i]) % mod;
    }
    
    stack<pair<int, int>> St;
    St.push({0, -1});
    for (int i = 1; i <= n; i++) {
        int last = St.top().first;
        int self = P2[i];

        while (St.size() && St.top().first != 0 && cmp(St.top().first, St.top().second, self, i)) {
            self += St.top().second;
            St.pop();
            last = St.top().first;
        }

        Ans[i] = (Ans[last] + 1LL * power(2, self, mod) * A[i]) % mod;
        Ans[i] += ((Ps[i - 1] - Ps[last] % mod) + mod) % mod;
        Ans[i] %= mod;

        cout << Ans[i] << " ";

        St.push({i, self});
    }

    cout << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 