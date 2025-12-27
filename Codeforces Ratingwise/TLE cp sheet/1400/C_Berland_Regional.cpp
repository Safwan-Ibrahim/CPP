// Created on: 2025-02-25 01:45
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 2e5 + 8;
vector<ll> A[N]; // remember to clear in every try

void Try() {
    int n; cin >> n;
    vector<int>U(n + 1, 0), S(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> U[i];
    }
    
    for (int i = 1; i <= n; i++) {
        cin >> S[i];
    }

    for (int i = 1; i <= n; i++) {
        A[U[i]].push_back(S[i]);
    }

    for (int i = 1; i <= n; i++) {
        sort(A[i].rbegin(), A[i].rend());
    }

    for (int i = 1; i <= n; i++) {
        ll ans = 0;
        for (int j = 0; j < A[i].size(); j++) {
            ans += A[i][j];
            A[i][j] = ans;
        }
    }

    map<int, ll>Ans;

    for (int i = 1; i <= n; i++) {
        for (int j = 0, sz = A[i].size(); j < sz; j++) {
            int id = sz - sz % (j + 1) - 1;
            Ans[j + 1] += A[i][id];
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << Ans[i] << " ";
    }
    cout << endl;

    for (int i = 1; i <= n; i++) {
        A[i].clear();
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