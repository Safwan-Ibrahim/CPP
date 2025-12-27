// Created on: 2025-11-27 21:57
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;

    set<char> St;
    string S = "#";
    map<char, int> F;
    for (int i = 1; i <= n; i++) {
        char c; cin >> c;
        St.insert(c);
        S += c;
        F[c]++;
    }
    
    if (St.size() == 1) {
        cout << -1 << endl; return;
    }

    vector<int> C;
    for (auto [x, y] : F) {
        C.push_back(y);
    }
    
    sort(C.begin(), C.end());
    if (C.size() == 2) {
        C.insert(C.begin(), 0);
    }
    
    int a = C[2], b = C[1], c = C[0];
    
    int x, y; bool normal = true;
    for (int i = 1; i <= n; i++) {
        if (i + 1 <= n && F[S[i]] == a && S[i + 1] != S[i]) {
            x = i, y = i + 1;
            break;
        }
        if (i - 1 >= 1 && F[S[i]] == a && S[i] != S[i - 1]) {
            x = i - 1, y = i; normal = false;
            break;
        }
    }
    
    vector<int> Ans;
    if (normal) {
        for (int i = 1; i <= (a - c) * 2; i++) {
            Ans.push_back(x);
        }
        for (int i = 1; i <= (b - c) * 2; i++) {
            if (F[S[y]] == b) {
                Ans.push_back(y);
            }
            else {
                Ans.push_back(y + 1);
            }
        }
    }
    else {
        for (int i = 1; i <= (a - c) * 2; i++) {
            Ans.push_back(x + i - 1);
        }
        for (int i = 1; i <= (b - c) * 2; i++) {
            if (F[S[x]] == b) {
                Ans.push_back(x + (a - c) * 2);
            }
            else {
                Ans.push_back(x + (a - c) * 2 - 1);
            }
        }
    }

    cout << Ans.size() << endl;
    for (auto x : Ans) {
        cout << x << endl;
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