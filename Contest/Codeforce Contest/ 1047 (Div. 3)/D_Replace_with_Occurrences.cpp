// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, A[nn], B[nn];

void Try() {
    int n; cin >> n;
    
    set<int> St;
    map<int, vector<int>> Mp;
    for (int i = 1; i <= n; i++) {
        cin >> B[i];
        St.insert(B[i]);
        Mp[B[i]].push_back(i);
    }

    ll sum = 0;
    for (auto x : St) {
        sum += x;
    }

    if (sum > n) {
        cout << -1 << endl; return;
    }

    int cnt = 1;
    for (auto [x, vec] : Mp) {
        if (vec.size() % x != 0) {
            cout << -1 << endl; return;
        }
        for (int i = 0, c = 1; i < vec.size(); i++, c++) {
            A[vec[i]] = cnt;
            if (c % x == 0) cnt++;
        }
    }

    map<int, int>Cnt;
    for (int i = 1; i <= n; i++) {
        Cnt[A[i]]++;
    }

    for (int i = 1; i <= n; i++) {
        assert(Cnt[A[i]] == B[i]);
    }

    for (int i = 1; i <= n; i++) {
        cout << A[i] << " ";
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