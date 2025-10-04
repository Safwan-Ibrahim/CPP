// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

struct FBS {
    int n;                     // number of bits
    vector<uint64_t> a;        // words

    FBS(int n_) : n(n_), a((n_ + 63) >> 6) {}

    void set(int i) { a[i >> 6] |= 1ULL << (i & 63); }
    void unset(int i) { a[i >> 6] &= ~(1ULL << (i & 63)); }
    void flip(int i) { a[i >> 6] ^= 1ULL << (i & 63); }
    bool test(int i) const { return (a[i >> 6] >> (i & 63)) & 1ULL; }

    void mask_tail() {
        int bits_in_last = n & 63;
        if (bits_in_last) a.back() &= (1ULL << bits_in_last) - 1ULL;
    }

    FBS operator<<(int k) const {
        FBS res(n);
        int shift_words = k >> 6, shift_bits = k & 63;
        for (int i = (int)a.size() - 1; i >= 0; i--) {
            uint64_t x = 0;
            if (i - shift_words >= 0) {
                x = a[i - shift_words] << shift_bits;
                if (shift_bits && i - shift_words - 1 >= 0)
                    x |= a[i - shift_words - 1] >> (64 - shift_bits);
            }
            res.a[i] = x;
        }
        res.mask_tail();
        return res;
    }

    void or_equal(const FBS &other) {
        for (size_t i = 0; i < a.size(); i++) a[i] |= other.a[i];
        mask_tail();
    }

    FBS& operator|=(const FBS &other) { or_equal(other); return *this; }

    int msb() const {
        for (int i = (int)a.size() - 1; i >= 0; i--) {
            if (a[i]) return (i << 6) + (63 - __builtin_clzll(a[i]));
        }
        return -1;
    }

    int msb_leq(int k) const {
        if (k >= n) k = n - 1;
        int block = k >> 6;
        int bit = k & 63;
        uint64_t mask = (1ULL << (bit + 1)) - 1;
        for (int i = block; i >= 0; i--) {
            uint64_t x = a[i];
            if (i == block) x &= mask;
            if (x) return (i << 6) + (63 - __builtin_clzll(x));
        }
        return -1;
    }

    int lsb() const {
        for (size_t i = 0; i < a.size(); i++) {
            if (a[i]) return (i << 6) + __builtin_ctzll(a[i]);
        }
        return -1;
    }

    int count() const {
        int res = 0;
        for (auto x : a) res += __builtin_popcountll(x);
        return res;
    }

    void flip_all() {
        for (auto &x : a) x = ~x;
        mask_tail();
    }
};


const int nn = 2e5 + 17;
vector<int> G[nn];
int n, mn, mx;

void Try() {
    cin >> n >> mn;
    
    for (int i = 2; i <= n; i++) {
        int x; cin >> x;
        G[x].push_back(i);
    }
    
    mx = n - mn;
    if (mn > mx) swap(mn, mx);

    queue<int> Q;
    vector<int> Dis(n + 1, 0);
    Q.push(1); Dis[1] = 1;

    int s = 1e9;

    while (Q.size()) {
        int u = Q.front(); Q.pop();
        for (auto v : G[u]) {
            Dis[v] = Dis[u] + 1;
            Q.push(v);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (G[i].size() == 0) s = min(s, Dis[i]);
    }
    
    map<int, int> Cnt;
    for (int i = 1; i <= n; i++) {
        if (Dis[i] <= s) {
            Cnt[Dis[i]]++;
        }
    }       

    vector<int> V;
    for (auto [x, y] : Cnt) {
        V.push_back(y);
    }

    sort(V.begin(), V.end());    
    int m = V.size();
    
    FBS Ans(mn + 1);
    int ans = 1;
    Ans.set(0);
    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum += V[i];
        Ans.or_equal(Ans << V[i]);
        int msb = Ans.msb();
        if (sum - msb <= mx) ans = i + 1;
    }

    cout << ans << endl;

    for (int i = 1; i <= n; i++) {
        G[i].clear();
    }

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 