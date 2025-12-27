// Created on: 2025-12-25 23:39
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 17;
int n, A[nn]; ll Ps[nn];

bool ok(ll x) {
    deque<int> Dq;
    vector<ll> Min_cost(n + 2);

    Dq.push_back(0);
    for (int i = 1; i <= n + 1; i++) {
        while (Dq.size() && Ps[i - 1] - Ps[Dq.front()] > x) Dq.pop_front();

        assert(Dq.size());

        Min_cost[i] = A[i] + Min_cost[Dq.front()];

        while (Dq.size() && Min_cost[Dq.back()] >= Min_cost[i]) Dq.pop_back();

        Dq.push_back(i);
    }

    return Min_cost[n + 1] <= x;
}

void Try() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    A[n + 1] = 0;

    for (int i = 1; i <= n; i++) {
        Ps[i] = Ps[i - 1] + A[i];
    }

    ll lo = 0, hi = accumulate(A + 1, A + n + 1, 0LL);
    while (lo + 1 < hi) {
        ll mid = lo + hi >> 1;
        if (ok(mid)) {
            hi = mid;
        }
        else lo = mid;
    }

    cout << hi << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 