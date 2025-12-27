// Created on: 2025-05-22 03:07
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 3e5 + 8;
int n, A[nn];

void Try() {
    cin >> n; int mx = -2e9;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        mx = max(mx, A[i]);
    }
    
    if (mx == 0) {
        cout << "NO\n"; return;
    }

    cout << "YES\n";
    vector<int>Pos, Neg;
    for (int i = 1; i <= n; i++) {
        if (A[i] == 0) cout << A[i] << " ";
        else {
            if (A[i] > 0) Pos.push_back(A[i]);
            else Neg.push_back(-A[i]);
        }
    }

    ll sum = 0;
    while(Pos.size() || Neg.size()) {
        if (sum >= 0) {
            sum -= Neg.back();
            cout << -Neg.back() << " ";
            Neg.pop_back();
        }
        else {
            sum += Pos.back();
            cout << Pos.back() << " ";
            Pos.pop_back();
        }
    }

    cout << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 