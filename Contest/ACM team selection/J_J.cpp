// Created on: 2025-02-09 16:09
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5 + 7;
int n, m, A[N], P[N], S[N];
pair<int, int> Q[N];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    int mx = -1, mx_cnt = 0;
    int mn = INT_MAX, mn_cnt = 0;

    memset(P, 0, n * 4);
    memset(S, 0, n * 4);

    for (int i = 1; i <= n; i++) {
        if (A[i] > mx) {
            mx = A[i];
            mx_cnt++;
        }
        P[i] = mx_cnt;
    }

    for (int i = n; i >= 1; i--) {
        if (A[i] < mn) {
            mn = A[i];
            mn_cnt++;
        }
        S[i] = mn_cnt;
    }

    set<pair<int, int>>St;
    for (int i = 1; i <= m; i++) {
        int id, x; 
        cin >> id >> x;
        Q[i] = {id, x};
        St.insert({id, x});
    }

    map<pair<int, int>, int>Ans;
    for (int i = 1; i <= n; i++) {
        auto it = St.begin();
        while(!St.empty()) {
            if (it->first >= i) {
                break;
            }
            else {
                if (it->second < A[i]) {
                    Ans[{it->first, it->second}] = i;
                    St.erase(it);
                }
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
} 