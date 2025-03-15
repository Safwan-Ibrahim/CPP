// Created on: 2025-02-26 17:52
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    priority_queue<pair<int, int>>Pq;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (x != 0) {
            Pq.push({x, i});
        }
    }
    
    vector<pair<int, int>>Ans;
    while(Pq.size() >= 2) {
        auto [x, y] = Pq.top();
        Pq.pop();
        auto [a, b] = Pq.top();
        Pq.pop();
        Ans.push_back({y, b});
        if (a - 1 > 0) {
            Pq.push({a - 1, b});
        }
        if (x - 1 > 0) {
            Pq.push({x - 1, y});
        } 
    }  
    
    cout << Ans.size() <<  endl;
    for (auto [x, y] : Ans) {
        cout << x << ' ' << y << endl;
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