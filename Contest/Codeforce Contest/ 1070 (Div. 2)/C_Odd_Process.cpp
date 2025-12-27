// Created on: 2025-12-11 21:18
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void Try() {
    int n; cin >> n;

    vector<int> Mx, E;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (x & 1) E.push_back(x);
        else Mx.push_back(x);
    }

    if (Mx.size() == n) {
        for (int i = 1; i <= n; i++) {
            cout << 0 << " ";
        }
        cout << endl; return;
    }

    sort(E.begin(), E.end());
    sort(Mx.rbegin(), Mx.rend());

    Mx.insert(Mx.begin(), E.back());
    E.pop_back();

    int mx = Mx.size();

    for (int i = 1; i < mx; i++) {
        Mx[i] += Mx[i - 1];
    }

    Mx.insert(Mx.begin(), 0);
    for (int k = 1; k <= n; k++) {
        if (k <= mx) {
            cout << Mx[k] << " ";
        }
        else {
            int mst = k - mx;
            if (mst & 1) {
                if (mst == E.size()) {
                    cout << 0 << " ";
                }
                else cout << Mx[mx - 1] << " ";
            }
            else cout << Mx.back() << " ";
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