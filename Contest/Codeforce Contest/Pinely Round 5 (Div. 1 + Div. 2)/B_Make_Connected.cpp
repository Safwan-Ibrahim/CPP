// Created on: 2025-10-30 22:59
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 110;
char S[nn][nn];
int n;

void Try() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> S[i][j];
        }
    }
    
    vector<pair<int, int>> P;
    for (int row = 1; row <= n; row++) {
        int cnt = 0;
        for (int col = 1; col <= n; col++) {
            cnt += S[row][col] == '#';
            if (S[row][col] == '#'){
                P.push_back({row, col});
            }
        }

        if (cnt > 2) {
            cout << "NO\n"; return;
        }
    }

    for (int col = 1; col <= n; col++) {
        int cnt = 0;
        for (int row = 1; row <= n; row++) {
            cnt += S[row][col] == '#';
        }

        if (cnt > 2) {
            cout << "NO\n"; return;
        }
    }

    for (int i = 0; i < P.size(); i++) {
        set<pair<int, int>> St;
        for (int j = i + 1; j < P.size(); j++) {
            int x = abs(P[i].first - P[j].first);
            int y = abs(P[i].second - P[j].second);
            if (abs(x - y) > 1) {
                cout << "NO\n"; return;
            }
            St.insert({P[j].second - P[i].second, P[j].first - P[i].first});
        }
        for (auto [x, y] : St) {
            if (max(abs(x), abs(y)) >= 2 && St.count({y, x}) && x != y) {
                cout << "NO\n"; return;
            }
        }
    }

    cout << "YES\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 