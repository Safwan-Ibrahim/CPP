// Created on: 2025-02-18 02:00
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 2e5 + 8;
int A[N];

void Try() {
    int n, m, v; cin >> n >> m >> v;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    vector<ll>P(n + 2, 0), S(n + 2, 0), PS(n + 2, 0);
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += A[i];
        if (sum >= v) {
            P[i]++;
            sum = 0;
        }
        P[i] += P[i - 1];
        PS[i] += PS[i - 1] + A[i];
    }

    if (P[n] < m) {
        cout << -1 << endl;
        return;
    }

    sum = 0;
    for (int i = n; i >= 1; i--) {
        sum += A[i];
        if (sum >= v) {
            S[i]++;
            sum = 0; 
        }
        S[i] += S[i + 1];
    }

    ll ans = 0;
    for (int l = 1; l <= n; l++) {
        int need = m - P[l - 1];
        int lo = l, hi = n + 1, got = -1;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if (S[mid] > need) {
                lo = mid + 1;
            }
            else if (S[mid] < need) {
                hi = mid - 1;
            }
            else {
                got = mid;
                lo = mid + 1;
            }
        }
        if (got != -1) {
            ans = max(ans, PS[got - 1] - PS[l - 1]);
        }
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