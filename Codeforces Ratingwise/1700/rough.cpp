// Created on: 2025-08-28 08:50
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n; cin >> n;
    int A[n + 1];

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    vector<vector<int>>SS;
    SS.push_back({});

    for (int i = 1; i <= n; i++) {
        vector<int>Tmp;
        vector<vector<int>>Stmp;
        for (auto V : SS) {
            Tmp = V;
            Tmp.push_back(A[i]);
            Stmp.push_back(Tmp);
        }
        for (auto Tmp : Stmp) {
            SS.push_back(Tmp);
        }
    }

    for (auto V : SS) {
        for (auto x : V) {
            cout << x << " ";
        }
        cout << endl;
    }
    
    return 0;
} 