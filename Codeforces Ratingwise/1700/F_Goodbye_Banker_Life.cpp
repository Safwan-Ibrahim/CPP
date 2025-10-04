// Created on: 2025-06-26 15:29
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int n, k; 

vector<int> Rec(int x) {
    vector<int>Ans;
    if (x <= 1) {
        return {1};
    }
    if (x % 2 == 1) {
        vector<int>Prev = Rec(x - 1);
        for (int j = 0; j < x; j++) {
            if (j == 0 || j == x - 1) Ans.push_back(1);
            else Ans.push_back(Prev[j - 1] ^ Prev[j]);
        }
    }
    if (x % 2 == 0) {
        vector<int>Prev = Rec(x / 2);
        for (auto x : Prev) {
            Ans.push_back(x);
            Ans.push_back(x);
        }
    }
    return Ans;
}

void Try() {
    cin >> n >> k;

    vector<int>Ans = Rec(n);
    
    for (auto x : Ans) {
        cout << (x ? k : 0) << " ";
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