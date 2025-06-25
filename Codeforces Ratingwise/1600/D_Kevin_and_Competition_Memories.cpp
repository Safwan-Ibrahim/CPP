// Created on: 2025-06-15 02:23
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 3e5 + 17;
vector<int>A, B;
int pn, tn;

void Try() {
    cin >> pn >> tn;
    A.resize(pn); B.resize(tn);
    for (auto &x : A) {
        cin >> x;
    }
    for (auto &x : B) {
        cin >> x;
    }

    int kevin = A[0];
    sort(A.begin(), A.end());
    for (auto &x : B) {
        int cost = 0;
        if (x > kevin) {
            cost = A.end() - lower_bound(A.begin(), A.end(), x);
        }
        x = cost;
    }

    sort(B.begin(), B.end());

    for (int i = 1; i <= tn; i++) {
        ll ans = 0;
        for (int j = i - 1; j < B.size(); j += i) {
            ans += B[j] + 1;
        }
        cout << ans << " ";
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