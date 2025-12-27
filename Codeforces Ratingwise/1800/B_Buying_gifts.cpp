// Created on: 2025-12-09 14:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 5e5 + 17;
int n, A[nn], B[nn], Smx[nn];

void Try() {
    cin >> n;

    vector<pair<int, int>> V(n);
    for (int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        V[i - 1] = {x, y};
    }

    sort(V.begin(), V.end());

    for (int i = 1; i <= n; i++) {
        A[i] = V[i - 1].first;
        B[i] = V[i - 1].second;
    }
    
    int mx = -1;
    for (int i = n; i >= 1; i--) {
        Smx[i] = mx = max(mx, B[i]);
    }

    set<int> St;
    int ans = 1e9 + 7;
    for (int i = 1; i <= n; i++) {
        int c = 1e9 + 7;
        if (i == n) {

            auto it = St.lower_bound(A[i]);
            if (it != St.end()) {
                c = min(c, abs(*it - A[i]));
            }
            if (it != St.begin()) {
                it--;
                c = min(c, abs(*it - A[i]));
            }
        }
        else {
            c = min(c, abs(A[i] - Smx[i + 1]));

            if (i > 1 && A[i] > Smx[i + 1]) {
                auto it = St.lower_bound(A[i]);
                if (it != St.end()) {
                    c = min(c, abs(*it - A[i]));
                }

                if (it != St.begin()) {
                    it--;
                    if (*it > Smx[i + 1]) {
                        c = min(c, abs(A[i] - *it));
                    }
                }
            }
        }

        ans = min(ans, c);
        St.insert(B[i]);
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