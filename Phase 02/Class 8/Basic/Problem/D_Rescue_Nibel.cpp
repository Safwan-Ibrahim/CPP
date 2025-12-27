// Created on: 2025-11-18 12:40
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int nn = 3e5 + 17, mod = 998244353;
int Fact[nn], IFact[nn];

int power(int x, int n) {
    int ans = 1 % mod;
    while(n > 0) {
        if (n & 1) {
            ans = 1LL * ans * x % mod;
        }
        n >>= 1;
        x = 1LL * x * x % mod;
    }  
    return ans; 
}

void prec() {
    int n = nn - 5;
    Fact[0] = 1 % mod;
    for (int i = 1; i <= n; i++) {
        Fact[i] = 1LL * Fact[i - 1] * i % mod;
    }

    IFact[n] = power(Fact[n], mod - 2);
    for (int i = n - 1; i >= 0; i--) { 
        IFact[i] = 1LL * IFact[i + 1] * (i + 1) % mod;
    }
}

int nCr(int n, int r) {
    if (r > n || r < 0) return 0;
    return 1LL * Fact[n] * IFact[r] % mod * IFact[n - r] % mod;
}

int nPr(int n, int r) {
    if (r > n || r < 0) return 0;
    return 1LL * Fact[n] * IFact[n - r] % mod;
}

void Try() {
    int n, k; cin >> n >> k;

    map<int, vector<int>> Mp;
    for (int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        Mp[x].push_back(y);
    }

    int ans = 0, cnt = 0, id = 0;
    o_set<pair<int, int>> R;
    for (auto [x, v] : Mp) {
        cnt += v.size();
        for (auto r : v) {
            R.insert({r, ++id});
        }
        int have = cnt - R.order_of_key({x, -id});
        ans += nCr(have, k); ans %= mod;
        ans -= nCr(have - v.size(), k); ans %= mod;
        ans += mod; ans %= mod;
    }

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    prec(); int t = 1;
    for (int i = 1; i <= t; i++) {
        Try();
    }

    return 0;
} 