// Created on: 2025-03-07 21:57
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, k; cin >> n >> k;
    set<int>St;
    int A[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        St.insert(A[i]);
    }
    
    if (St.size() > k) {
        cout << -1 << endl; return;
    }

    int sq = 1;
    while(St.size() < k) {
        while(St.find(sq) != St.end()) {
            sq++;
        }
        St.insert(sq++);
    }
    vector<int>V{St.begin(), St.end()};


    vector<int>Ans;
    for (int i = 1; i <= n; i++) {
        for (auto x : V) {
            Ans.push_back(x);
        }
    }

    cout << Ans.size() << endl;
    for (int i = 0; i < (int)Ans.size(); i++) {
        cout << Ans[i] << " ";
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