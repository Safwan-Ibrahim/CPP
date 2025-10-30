// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, m, cnt;

int query(vector<int> &V) {
    cnt++;
    assert(!V.empty());
    cout << "? " << V.size() << " ";
    for (auto x : V) cout << x << " ";
    cout << endl;
    int ans; cin >> ans; return ans;
}

void Try() {
    cin >> n; m = 2 * n;

    cnt = 0;
    vector<int> Ans(m + 1, -1);
    vector<int> Q; Q.push_back(1);
    vector<int> Nq;

    for (int i = 2; i <= m; i++) {
        Q.push_back(i);
        int ans = query(Q);
        if (ans) {
            Ans[i] = ans;
            Q.pop_back();
            Nq.push_back(i);
        }
    }

    for (int i = 0; i < Q.size(); i++) {
        Nq.push_back(Q[i]);
        int ans = query(Nq);
        assert(ans);
        Ans[Q[i]] = ans;
        Nq.pop_back();
        assert(cnt <= 3 * n);
    }

    cout << "! " << " ";
    for (int i = 1; i <= m; i++) {
        assert(Ans[i] != -1);
        cout << Ans[i] << " ";
    }
    cout << endl;
    
}

int32_t main() {

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 