// Created on: 2025-07-05 18:17
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, A[nn];
array<int, 4>Ans;

void store_max(int x, const vector<int>&V) {
    pair<int, int> mn = {1e9, 0};
    for (int i = 0; i < V.size(); i++) {
        if (2 * i - V[i] < mn.first) {
            mn = {2 * i - V[i], V[i]};
        } 
        int self = 2 * i - V[i] + 1;
        if (self - mn.first > Ans[0]) {
            Ans[0] = self - mn.first, Ans[1] = x, Ans[2] = mn.second, Ans[3] = V[i];
        }
    }
}

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    map<int, vector<int>>Mp;
    for (int i = 1; i <= n; i++) {
        Mp[A[i]].push_back(i);
    }
    
    Ans[0] = -1e9;
    for (auto [x, vec] : Mp) {
        store_max(x, vec);
    }

    cout << Ans[1] << " " << Ans[2] << " " << Ans[3] << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 