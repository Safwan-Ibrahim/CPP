// Created on: 2025-08-17 04:17
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, q, A[nn]; char S[nn];

void Try() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> S[i];
        S[i] = (S[i] == 'L' ? '0' : '1');
    }

    S[n + 1] = '2';
    vector<int>D(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int mn = A[i], mx = i;
        if (mn > mx) swap(mx, mn);
        D[mn]++, D[mx]--;
    }

    for (int i = 1; i <= n; i++) {
        D[i] += D[i - 1];
    }

    set<int>Pb;
    for (int i = 1; i + 1 < n; i++) {
        if (D[i] && S[i] == '0' && S[i + 1] == '1') Pb.insert(i);
    }

    while(q--) {
        int i; cin >> i;
        S[i] ^= 1;
        if (S[i - 1] == '0' && S[i] == '1' && D[i - 1]) Pb.insert(i - 1);
        else Pb.erase(i - 1);
        if (S[i] == '0' && S[i + 1] == '1' && D[i]) Pb.insert(i);
        else Pb.erase(i);
        cout << (Pb.empty() ? "YES\n" : "NO\n");
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 