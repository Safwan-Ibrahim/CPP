// Created on: 2025-08-19 21:35
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 3e5 + 17, inf = 1e6;
int n, m, A[nn], B[nn]; ll Ps[nn];

vector<vector<int>>Ans;

int min_cost(int l, int i) {
    if (l >= n) return 0;
    if (i > m) return inf;

    int &ans = Ans[l][i];
    if (ans != -1) return ans;

    int lo = l + 1, hi = n, nxt = -1;
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        ll ps = Ps[mid] - Ps[l];
        if (ps <= B[i]) {
            nxt = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    
    if (nxt == -1) return inf;
    ans = m - i + min_cost(nxt, i);
    ans = min(ans, min_cost(l, i + 1));
    return ans;
}

void Try() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> B[i];
    }

    for (int i = 1; i <= n; i++) {
        Ps[i] = Ps[i - 1] + A[i];
    }

    Ans = vector<vector<int>> (n + 1, vector<int>(m + 1, -1));
    int ans = min_cost(0, 1);
    cout << (ans >= inf ? -1 : ans) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 