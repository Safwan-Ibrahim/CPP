// Created on: 2025-04-16 03:27
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 8;
vector<int> Add[nn], Rem[nn];

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, q; cin >> n >> q;
    while(q--) {
        int l, r, x; cin >> l >> r >> x;
        Add[l].push_back(x);
        Rem[r + 1].push_back(x);
    }

    map<int, int>Mp;
    for (int i = 1; i <= n; i++) {
        for (auto x : Add[i]) {
            Mp[x]++;
        }
        for (auto x : Rem[i]) {
            Mp[x]--;
            if (Mp[x] == 0) {
                Mp.erase(x);
            }
        }
        cout << Mp.size() << endl;
    }

    return 0;
} 