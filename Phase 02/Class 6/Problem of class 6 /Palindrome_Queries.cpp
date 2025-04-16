// Created on: 2025-04-15 01:23
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 8;
string S, P;
int n;

const int m0 = 127657753, m1 = 987654319;
const int p0 = 79, p1 = 97;
int Pow[2][nn], Ipow[2][nn];

int power(int x, int n, int mod) {
    int ans = 1 % mod;
    while (n > 0) {
        if (n & 1) ans = 1LL * ans * x % mod;
        x = 1LL * x * x % mod;
        n >>= 1;
    }
    return ans;
}

void prec() {
    Pow[0][0] = Pow[1][0] = 1;
    for (int i = 1; i < nn; i++) {
        Pow[0][i] = 1LL * Pow[0][i - 1] * p0 % m0;
        Pow[1][i] = 1LL * Pow[1][i - 1] * p1 % m1;
    }

    int ip0 = power(p0, m0 - 2, m0);
    int ip1 = power(p1, m1 - 2, m1);
    Ipow[0][0] = Ipow[1][0] = 1;

    for (int i = 1; i < nn; i++) {
        Ipow[0][i] = 1LL * Ipow[0][i - 1] * ip0 % m0;
        Ipow[1][i] = 1LL * Ipow[1][i - 1] * ip1 % m1;
    }
}


struct ST4 {
    int T[4 * nn];
    static const int inf = 1e9;
    void build(int node, int b, int e) {
        if (b == e) {
            T[node] = 1LL * Pow[0][b] * (S[b] - 'a' + 5) % m0;
            return;
        }
        int mid = (b + e) / 2, l = node * 2, r = node * 2 + 1;
        build(l, b, mid);
        build(r, mid + 1, e);
        T[node] = (1LL * T[l] + T[r]) % m0; 
    }

    int query(int node, int b, int e, int i, int j) {
        if (i <= b && j >= e) {
            return T[node];
        }
        else if (b > j || e < i) {
            return 0;
        }
        int mid = (b + e) / 2, l = node * 2, r = node * 2 + 1;
        return (1LL * query(l, b, mid, i, j) + query(r, mid + 1, e, i, j)) % m0;
    }

    void upd(int node, int b, int e, int id, char x) {
        if (b > id || e < id) {
            return;
        }
        if (b == e && b == id) {
            T[node] = 1LL * Pow[0][b] * (x - 'a' + 5) % m0;
            return;
        }
        int mid = (b + e) / 2, l = node * 2, r = node * 2 + 1;
        upd(l, b, mid, id, x);
        upd(r, mid + 1, e, id, x);
        T[node] = (1LL * T[l] + T[r]) % m0;
    }
}T1;

struct ST3 {
    int T[4 * nn];
    static const int inf = 1e9;
    void build(int node, int b, int e) {
        if (b == e) {
            T[node] = 1LL * Pow[1][b] * (S[b] - 'a' + 6) % m1;
            return;
        }
        int mid = (b + e) / 2, l = node * 2, r = node * 2 + 1;
        build(l, b, mid);
        build(r, mid + 1, e);
        T[node] = (1LL * T[l] + T[r]) % m1; 
    }

    int query(int node, int b, int e, int i, int j) {
        if (i <= b && j >= e) {
            return T[node];
        }
        else if (b > j || e < i) {
            return 0;
        }
        int mid = (b + e) / 2, l = node * 2, r = node * 2 + 1;
        return (1LL * query(l, b, mid, i, j) + query(r, mid + 1, e, i, j)) % m1;
    }

    void upd(int node, int b, int e, int id, char x) {
        if (b > id || e < id) {
            return;
        }
        if (b == e && b == id) {
            T[node] = 1LL * Pow[1][b] * (x - 'a' + 6) % m1;
            return;
        }
        int mid = (b + e) / 2, l = node * 2, r = node * 2 + 1;
        upd(l, b, mid, id, x);
        upd(r, mid + 1, e, id, x);
        T[node] = (1LL * T[l] + T[r]) % m1;
    }
}T2;

struct ST2 {
    int T[4 * nn];
    static const int inf = 1e9;
    void build(int node, int b, int e) {
        if (b == e) {
            T[node] = 1LL * Pow[0][b] * (P[b] - 'a' + 5) % m0;
            return;
        }
        int mid = (b + e) / 2, l = node * 2, r = node * 2 + 1;
        build(l, b, mid);
        build(r, mid + 1, e);
        T[node] = (1LL * T[l] + T[r]) % m0; 
    }

    int query(int node, int b, int e, int i, int j) {
        if (i <= b && j >= e) {
            return T[node];
        }
        else if (b > j || e < i) {
            return 0;
        }
        int mid = (b + e) / 2, l = node * 2, r = node * 2 + 1;
        return (1LL * query(l, b, mid, i, j) + query(r, mid + 1, e, i, j)) % m0;
    }

    void upd(int node, int b, int e, int id, char x) {
        if (b > id || e < id) {
            return;
        }
        if (b == e && b == id) {
            T[node] = 1LL * Pow[0][b] * (x - 'a' + 5) % m0;
            return;
        }
        int mid = (b + e) / 2, l = node * 2, r = node * 2 + 1;
        upd(l, b, mid, id, x);
        upd(r, mid + 1, e, id, x);
        T[node] = (1LL * T[l] + T[r]) % m0;
    }
}T3;

struct ST1 {
    int T[4 * nn];
    static const int inf = 1e9;
    void build(int node, int b, int e) {
        if (b == e) {
            T[node] = 1LL * Pow[1][b] * (P[b] - 'a' + 6) % m1;
            return;
        }
        int mid = (b + e) / 2, l = node * 2, r = node * 2 + 1;
        build(l, b, mid);
        build(r, mid + 1, e);
        T[node] = (1LL * T[l] + T[r]) % m1; 
    }

    int query(int node, int b, int e, int i, int j) {
        if (i <= b && j >= e) {
            return T[node];
        }
        else if (b > j || e < i) {
            return 0;
        }
        int mid = (b + e) / 2, l = node * 2, r = node * 2 + 1;
        return (1LL * query(l, b, mid, i, j) + query(r, mid + 1, e, i, j)) % m1;
    }

    void upd(int node, int b, int e, int id, char x) {
        if (b > id || e < id) {
            return;
        }
        if (b == e && b == id) {
            T[node] = 1LL * Pow[1][b] * (x - 'a' + 6) % m1;
            return;
        }
        int mid = (b + e) / 2, l = node * 2, r = node * 2 + 1;
        upd(l, b, mid, id, x);
        upd(r, mid + 1, e, id, x);
        T[node] = (1LL * T[l] + T[r]) % m1;
    }
}T4;

bool is_pali(int i, int j) {
    int h0 = 1LL * T1.query(1, 0, n - 1, i, j) * Ipow[0][i] % m0;
    int h1 = 1LL * T2.query(1, 0, n - 1, i, j) * Ipow[1][i] % m1;
    
    int h2 = 1LL * T3.query(1, 0, n - 1, n - j - 1, n - i - 1) * Ipow[0][n - j - 1] % m0;
    int h3 = 1LL * T4.query(1, 0, n - 1, n - j - 1, n - i - 1) * Ipow[1][n - j - 1] % m1;
    return h0 == h2 && h1 == h3; 
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int q; cin >> n >> q;
    prec();
    cin >> S;
    P = S;
    reverse(P.begin(), P.end());
    T1.build(1, 0, n - 1), T2.build(1, 0, n - 1);
    T3.build(1, 0, n - 1), T4.build(1, 0, n - 1);
    while(q--) {
        int ty; cin >> ty;
        if (ty == 2) {
            int l, r; cin >> l >> r;
            l--, r--;
            cout << (is_pali(l, r) ? "YES\n" : "NO\n");
        }
        else {
            int id; char c;
            cin >> id >> c;
            id--;
            T1.upd(1, 0, n - 1, id, c);
            T2.upd(1, 0, n - 1, id, c);
            T3.upd(1, 0, n - 1, n - id - 1, c);
            T4.upd(1, 0, n - 1, n - id - 1, c);
        }
    }
    
    
    return 0;
} 