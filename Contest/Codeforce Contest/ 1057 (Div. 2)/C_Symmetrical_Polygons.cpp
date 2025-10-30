// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n;

bool pos(ll sum, int mx, int x, int y = 0) {
    sum += x + y;
    mx = max({mx, x, y});
    return (sum + 1) / 2 > mx;
}

void Try() {
    cin >> n;

    map<int, int> Mp;
    vector<int> A;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        Mp[x]++;
    }
    
    int mx = 0, cnt = 0; ll sum = 0; 
    for (auto [x, y] : Mp) {
        sum += 1LL * x * (y - y % 2);
        mx = max(mx, x * (y % 2 == 0));
        cnt += y - y % 2;
        if (y & 1) A.push_back(x);
    }

    sort(A.begin(), A.end());

    n = A.size();
    ll ans = sum * (cnt > 2);
    for (int i = 0; i < n; i++) {
        int x = A[i], y = (i + 1 < n ? A[i + 1] : 0);
        ans = max(ans, (sum + x) * pos(sum, mx, x));
        ans = max(ans, (sum + x + y) * pos(sum, mx, x, y));
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