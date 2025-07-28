// Created on: 2025-07-24 21:07
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int mod = 998244353;
map<int, vector<array<int, 3>>>Mp;
int n, m, all = 1;
map<int, int>Ans;

int power(int x, int n, int m) {
    int ans = 1 % m;
    while(n > 0) {
        if (n & 1) {
            ans = 1LL * ans * x % m;
        }
        n >>= 1;
        x = 1LL * x * x % m;
    }
    return ans;
}

int inverse(int x) {
    return power(x, mod - 2, mod);
}

int exist(int p, int q) {
    int ans = p;
    ans = 1LL * ans * inverse(q) % mod;
    return ans;
}

int non_exist(int x) {
    int ans = (1 - x + mod) % mod;
    return ans;
}

int poss(int l) {
    if (l == m + 1) return all;
    if (Ans.find(l) != Ans.end()) return Ans[l];
    int ans = 0;
    for (auto [r, e, non] : Mp[l]) {
        ans = (ans + (1LL * poss(r + 1) * e % mod * inverse(non) % mod)) % mod;
    }
    return Ans[l] = ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    int l, r, q, p;
    for (int i = 1; i <= n; i++) {
        cin >> l >> r >> p >> q;
        int e = exist(p, q); int non = non_exist(e);
        Mp[l].push_back({r, e, non});
        all = 1LL * all * non % mod;
    }

    int ans = poss(1);
    cout << ans << endl;
    return 0;
} 