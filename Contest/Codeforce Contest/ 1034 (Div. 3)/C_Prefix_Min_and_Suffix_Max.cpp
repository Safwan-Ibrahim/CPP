// Created on: 2025-07-01 20:59
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, A[nn];

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {  
        cin >> A[i];
    }    

    vector<int>Pref_min(n + 3, 0), Suf_mx(n + 3, 0);
    Pref_min[0] = A[1], Suf_mx[n + 1] = A[n];

    int mn = 2e9;
    for (int i = 1; i <= n; i++) {
        mn = min(mn, A[i]);
        Pref_min[i] = mn;
    }
    int mx = -1;
    for (int i = n; i >= 1; i--) {
        mx = max(mx, A[i]);
        Suf_mx[i] = mx;
    }

    set<int>St;
    for (int i = 1; i <= n; i++) {
        int one = min(Pref_min[i - 1], A[i]);
        one = max(one, Suf_mx[i + 1]);
        St.insert(one);
        one = max(A[i], Suf_mx[i + 1]);
        one = min(one, Pref_min[i - 1]);
        St.insert(one);
    }

    for (int i = 1; i <= n; i++) {
        if (St.find(A[i]) != St.end()) {
            cout << '1';
        }
        else cout << '0';
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