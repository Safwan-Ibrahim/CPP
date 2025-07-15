// Created on: 2025-07-13 21:21
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

string S;

void shift(int l, int r, int k) {
    l--, r--;
    string Tmp = S.substr(l, r - l + 1);
    int n = Tmp.size();
    string lft = Tmp.substr(n - k, k);
    string rgt = Tmp.substr(0, n - k);
    Tmp = lft + rgt;
    for (int i = 0; i < n; i++) {
        S[i + l] = Tmp[i];
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> S;
    int q; cin >> q;
    int L[q + 1], R[q + 1], K[q + 1];
    for (int i = 1; i <= q; i++) {
        cin >> L[i] >> R[i] >> K[i]; K[i] %= (R[i] - L[i] + 1);
        shift(L[i], R[i], K[i]);
    }
    cout << S << endl;
    return 0;
} 