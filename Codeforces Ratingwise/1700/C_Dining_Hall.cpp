// Created on: 2025-06-25 22:23
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 5e4 + 18;
int n, A[nn];

set<array<int, 3>>St;
priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>>Pq;

void prec() {
    for (int i = 0; i <= 525; i++) {
        for (int j = 0; j <= 525; j++) {
            int x = 3 * i, y = 3 * j;
            Pq.push({x + y + 2, x + 1, y + 1});
            St.insert({x + y + 2, x + 1, y + 1});
            St.insert({x + y + 3, x + 1, y + 2});
            St.insert({x + y + 3, x + 2, y + 1});
            St.insert({x + y + 6, x + 2, y + 2});
        }
    }
}

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    set<array<int, 3>>Tmp;
    for (int i = 1; i <= n; i++) {
        if (A[i]) {
            auto [_, x, y] = *St.begin();
            St.erase(St.begin());
            Tmp.insert({_, x, y});
            if (x % 3 == 1 && y % 3 == 1) Pq.pop();
            cout << x << " " << y << endl;
        }
        else {
            auto [_, x, y] = Pq.top();
            Pq.pop(); St.erase({_, x, y});
            Tmp.insert({_, x, y});
            cout << x << " " << y << endl;
        }
    }

    for (auto [_, x, y] : Tmp) {
        St.insert({_, x, y});
        if (x % 3 == 1 && y % 3 == 1) {
            Pq.push({_, x, y});
        }
    }
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t; prec();
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 