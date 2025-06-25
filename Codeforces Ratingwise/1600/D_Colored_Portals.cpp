// Created on: 2025-06-19 19:58
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int inf = 2e9;

void Try() {
    int n, q; cin >> n >> q;
    string A[n + 5];
    vector<vector<int>>Mp(6);
    map<string, int>C; 
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        string S; cin >> S;
        if (C.find(S) == C.end()) {
            C[S] = cnt++;
        }
        Mp[C[S]].push_back(i);
        A[i] = S;
    }
    
    while(q--) {
        int x, y; cin >> x >> y;
        set<char>St; St.insert(A[x][0]); St.insert(A[x][1]); St.insert(A[y][0]); St.insert(A[y][1]);
        if (St.size() == 4) {
            int ans = inf;
            for (int i = 0; i < Mp.size(); i++) {
                if (i == C[A[x]] || i == C[A[y]]) continue;
                auto id = upper_bound(Mp[i].begin(), Mp[i].end(), x) - Mp[i].begin();
                if (id != Mp[i].size()) ans = min(ans, abs(Mp[i][id] - y) + abs(Mp[i][id] - x));
                if (id != 0) {
                    id--; ans = min(ans, abs(Mp[i][id] - y) + abs(Mp[i][id] - x));
                }
            }
            cout << (ans == inf ? -1 : ans) << endl;
        }
        else {
            cout << abs(x - y) << endl;
        }
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