// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int mxn = 1e4;
int n;

void Try() {
    cin >> n;

    string num = to_string(n);
    int len = num.size();
    
    vector<pair<int, int>> X;
    for (int i = 1; i <= num.size(); i++) {
        int x = stoi(num.substr(0, i));
        X.push_back({x, i});
    }
    
    int id = 0;
    while(num.size() < 8) {
        num.push_back(num[id++]);
        X.push_back({stoi(num), num.size()});
    }

    vector<pair<int, int>> Ans;
    for (int i = 1; i <= mxn; i++) {
        int m = n * i;
        for (auto [x, clen] : X) {
            int b = m - x;
            if (b < 1) break;
            int res_len = len * (i - b / len) - b % len;
            if (res_len == clen) {
                Ans.push_back({i, b});
            }
        }   
    }

    cout << Ans.size() << endl;
    for (auto [a, b] : Ans) {
        cout << a << " " << b << endl;
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