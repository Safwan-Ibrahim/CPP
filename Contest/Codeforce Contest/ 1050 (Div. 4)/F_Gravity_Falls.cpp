// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;

    vector<vector<int>> V;
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        vector<int> T;
        for (int j = 1; j <= k; j++) {
            int x; cin >> x;
            T.push_back(x);
        }
        V.push_back(T);
    }

    vector<int> Ans;
    while (V.size()) {
        sort(V.begin(), V.end());

        for (auto x : V[0]) {
            Ans.push_back(x);
        }

        vector<vector<int>> T;
        int s = V[0].size();
        for (auto vec : V) {
            if (vec.size() > s) {
                T.push_back({vec.begin() + s, vec.end()});
            }
        }

        V = T;
    }

    for (auto x : Ans) {
        cout << x << " ";
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