// Created on: 2025-05-08 20:00
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

vector<pair<ll, int>>V;

void prec() {
    vector<ll>A;

    ll num = 1;
    for (int i = 1; i <= 15; i++) {
        num *= i;
        A.push_back(num);
    }   

    int n = A.size();
    for (int subset = 0; subset < (1 << n); subset++) {
        ll sum = 0; int bit = 0;
        for (int mask = 0; mask < n; mask++) {
            if ((subset >> mask) & 1) {
                sum += A[mask];
                bit++;
            }
        }
        V.push_back({sum, bit});
    }

}

void Try() {
    ll n; cin >> n;
    int mn = 1e9;
    for (int i = 0; i < V.size() && V[i].first <= n; i++) {
        ll need = n - V[i].first;
        mn = min(__builtin_popcountll(need) + V[i].second, mn);
    }
    cout << mn << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    prec();
    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 