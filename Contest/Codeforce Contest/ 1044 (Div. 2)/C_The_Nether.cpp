// Created on: 2025-08-24 21:14
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int query(int x, vector<int>V) {
    cout << "? ";
    cout << x << " " << V.size() << " ";
    for (auto e : V) {
        cout << e << " ";
    }
    cout << endl; cout.flush();
    int ans; cin >> ans; return ans;
}

void Try() {
    int n; cin >> n;
    
    map<int, vector<int>>Mp;
    vector<int>A(n);
    int mx = 0;
    iota(A.begin(), A.end(), 1);
    for (int i = 1; i <= n; i++) {
        int ans = query(i, A);
        Mp[ans].push_back(i);
        mx = max(mx, ans);
    }
    
    vector<int>Ans;
    Ans.push_back(Mp[mx].front());
    for (int i = 2; i <= mx; i++) {
        vector<int>Tmp = Ans;
        for (auto x : Mp[mx - i + 1]) {
            Tmp.push_back(x);
            int ans = query(Ans.front(), Tmp);
            if (ans == i) {
                Ans.push_back(x); break;
            }
            Tmp.pop_back();
        }
    }

    cout << "! " << Ans.size() << " ";
    for (auto x : Ans) {
        cout << x << " ";
    }
    cout << endl; cout.flush();
}

int32_t main() {

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 