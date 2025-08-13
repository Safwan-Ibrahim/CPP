// Created on: 2025-08-07 21:36
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

bool cmp(pair<int, int>a, pair<int, int>b) {
    return (a.second + a.first) < (b.second + b.first);
}

void Try() {
    int n, k; cin >> n >> k;
    vector<pair<int, int>>V;
    int A[n + 1], B[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> B[i];
    }

    ll ans = 0;
    map<int, ll>Dif;
    for (int i = 1; i <= n; i++) {
        ans += abs(A[i] - B[i]);
        if (A[i] > B[i]) swap(A[i], B[i]);
        V.push_back({A[i], B[i]});
        Dif[A[i]]++, Dif[B[i] + 1]--;
    }

    ll sum = 0;
    for (auto [x, y] : Dif) {
        sum += y;
        Dif[x] = sum;
    }

    for (auto [x, y] : Dif) {
        if (y > 1) {
            cout << ans << endl; return;
        }
    }
    sort(V.begin(), V.end(), cmp);
    ll mn = 1e18;
    for (int i = 0; i + 1 < V.size(); i++) {
        ll cur = V[i].second - V[i].first + V[i + 1].second - V[i + 1].first;
        ll he = V[i + 1].first - V[i].first + V[i + 1].second - V[i].second;
        mn = min(mn, he - cur);
    }

    cout << ans + mn << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 