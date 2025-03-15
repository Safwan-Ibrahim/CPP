// Created on: 2025-03-11 22:18
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 2e5 + 8;
int P[N], R[N];

void Try() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> P[i];
    }   
    for (int i = 1; i <= n; i++) {
        cin >> R[i];
    }

    vector<pair<int, int>>A;
    for (int i = 1; i <= n; i++) {
        int a = P[i] - R[i];
        int b = P[i] + R[i];
        A.push_back({a, b});
    }

    sort(A.begin(), A.end());

    vector<int>Len, Cut;
    for (int i = 0; i < A.size(); i++) {
        Len.push_back(A[i].second - A[i].first + 1);
        for (int j = i + 1; j < A.size() && A[j].first <= A[i].second; j++) {
            Cut.push_back(min(A[i].second, A[j].second) - A[j].first + 1);
        }
    }

    ll ans = 0;
    for (auto x : Cut) {
        if (x % 2 == 0) {
            ll need = (x - 2) / 2;
            ans -= 2 * need * (need + 1);
            ans -= x;
        }
        else {
            if (x == 1) {
                ans -= 1;
            }
            else {
                ll need = x / 2;
                ans -= 2 * need * need;
                ans -= x;
            }
        }
    }

    for (auto x : Len) {
        if (x % 2 == 0) {
            ll need = (x - 2) / 2;
            ans += 2 * need * (need + 1);
            ans += x;
        }
        else {
            if (x == 1) {
                ans += 1;
            }
            else {
                ll need = x / 2;
                ans += 2 * need * need;
                ans += x;
            }
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