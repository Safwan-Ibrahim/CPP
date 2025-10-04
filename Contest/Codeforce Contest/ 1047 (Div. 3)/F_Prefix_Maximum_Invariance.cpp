// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17, mm = 25;
int n, A[nn], B[nn];

struct SPT {
    int St[nn][mm + 1];
    int Lg[nn + 1];

    SPT() {
        memset(St, 0, sizeof St);
        memset(Lg, 0, sizeof Lg);
    }

    void build(int n) {
        // precompute logs
        Lg[1] = 0;
        for (int i = 2; i <= n; i++) Lg[i] = Lg[i / 2] + 1;

        // base case: intervals of length 1
        for (int i = 1; i <= n; i++) St[i][0] = A[i];

        // build sparse table
        for (int j = 1; j <= mm; j++) {
            for (int i = 1; i + (1 << j) - 1 <= n; i++) {
                St[i][j] = max(St[i][j - 1], St[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query(int L, int R) {
        int j = Lg[R - L + 1];
        return max(St[L][j], St[R - (1 << j) + 1][j]);
    }

}T;

bool ok(int l, int r) {
    return T.query(l, r - 1) >= max(A[r], B[r]);
}

void Try() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> B[i];
    }

    T.build(n);

    ll ans = 0;
    for (int i = 1; i <= n; i++) {

        if (A[i] == B[i]) {
            ans += 1LL * i * (n - i + 1); continue;
        }

        int lo = 1, hi = i - 1;
        int id = 0;
        while(lo <= hi) {
            int mid = lo + hi >> 1;

            if (ok(mid, i)) {
                lo = mid + 1;
                id = mid;
            }   
            else hi = mid - 1;
        }

        ans += 1LL * (n - i + 1) * id;
    }
    
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 