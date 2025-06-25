// Created on: 2025-05-21 20:52
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e6 + 8;
vector<vector<int>>A;
map<int, int>Mp;

ll get_sum(ll x) {
    return x * (x + 1) * (2 * x + 1) / 6;
}

void prec() {
    int next = 2, cnt = 2;
    vector<int>Tmp;
    for (int i = 1; i <= nn; i++) {
        if (i == next || i == nn) {
            A.push_back(Tmp);
            Tmp.clear();
            next += cnt++;
        }
        Tmp.push_back(i);
    }

    int id = 0;
    next = 1, cnt = 1;
    do {
        Mp[next] = id++;
        next += cnt++;
    }
    while(next <= nn);
}

void Try() {
    int n; cin >> n;
    int id = (--Mp.upper_bound(n))->second;
    int mx, mn;
    for (int i = 0; i < A[id].size(); i++) {
        if (A[id][i] == n) {
            mx = mn = i; break;
        }
    }

    ll ans = 0;
    for (int i = id; i >= 0; i--) {
        ans += get_sum(A[i][mx]) - get_sum(A[i][mn] - 1);
        if (i != 0) {
            mn = max(0, mn - 1);
            mx = min((int) A[i - 1].size() - 1, mx);
        }
    }

    cout << ans << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t; prec();
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 