// Created on: 2025-06-21 10:24
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int pn, k, A[nn];

void Try() {
    cin >> pn >> k;
    for (int i = 1; i <= pn; i++) {
        cin >> A[i];
    }
    A[1] += k;

    vector<ll>Ps(pn + 2, 0);
    for (int i = 1; i <= pn; i++) {
        Ps[i] = Ps[i - 1] + A[i];
    }
    
    multiset<int>L, R;
    for (int i = 1; i <= pn; i++) {
        R.insert(A[i]);
    }

    for (int i = 1; i <= pn; i++) {
        R.erase(R.find(A[i]));
        auto rit = R.upper_bound(A[i]);
        auto lit = L.lower_bound(A[i]);
        if (rit != R.end()) {
            if (Ps[i] < *R.rbegin()) cout << i << " ";
            else cout << i - 1 << " ";
        }
        else if(lit != L.end()) {
            cout << i - 1 << " ";
        }
        else cout << 0 << " ";
        L.insert(A[i]);
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