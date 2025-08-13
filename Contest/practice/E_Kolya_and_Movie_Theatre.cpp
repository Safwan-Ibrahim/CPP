// Created on: 2025-08-06 22:15
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, m, d, A[nn];
map<pair<int, int>, ll>Ans;

ll get_max(int i, int last) {
    if (Ans.find({i, last}) != Ans.end()) {
        return Ans[{i, last}];
    }
    ll ans = 0;
    ans = get_max(i + 1, last);
    ans = max(ans, get_max(i + 1, i) + A[i] - 1LL * d * i - last);
    Ans[{i, last}] = ans;
    return ans;
}

void Try() {
    cin >> n >> m >> d;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
   cout << get_max(1, 0) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 