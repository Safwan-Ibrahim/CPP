// Created on: 2025-06-04 08:45
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 17;
int n, m, A[nn];

void Try() {
    cin >> n >> m;
    map<int, deque<int>>Mp;
    for (int i = 1; i <= m; i++) {
        string tmp; cin >> tmp;
        int first = stoi(tmp.substr(0, tmp.size() - 2));
        int last = stoi(tmp.substr(tmp.size() - 2, 2));
        Mp[first].push_back(last);
    }
    
    vector<vector<int>>Ans(n + 1, vector<int>(6, 0));
    for (int i = 1; i <= n; i += 2) {
        for (int j = 0; j < 6; j += 2) {
            Ans[i][j] = Mp.begin()->first * 100 + Mp.begin()->second.front();
            Ans[i][j + 1] = Mp.rbegin()->first * 100 + Mp.rbegin()->second.back();
        }
        if (i != n) {
            for (int j = 0; j < 6; j += 2) {
                Ans[i + 1][j] = Mp.rbegin()->first * 100 + Mp.rbegin()->second.back();
                Ans[i + 1][j + 1] = Mp.begin()->first * 100 + Mp.begin()->second.front();
            }
        }
        Mp[Mp.begin()->first].pop_front();
        if (Mp[Mp.begin()->first].empty()) {
            int id = Mp.begin()->first;
            Mp.erase(id);
        }
        if (Mp.size()) {
            Mp[Mp.rbegin()->first].pop_back();
            if (Mp[Mp.rbegin()->first].empty()) {
                int id = Mp.rbegin()->first;
                Mp.erase(id);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (auto x : Ans[i]) {
            cout << x << " ";
        }
        cout << endl;
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