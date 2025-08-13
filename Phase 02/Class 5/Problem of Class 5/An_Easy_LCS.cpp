// Created on: 2025-03-28 20:08
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

string S, T;
const int nn = 105;
string Ans[nn][nn];
bool Vs[nn][nn];

string lcs(int i, int j) {
    if (i == S.size() || j == T.size()) {
        return "";
    }
    if (Vs[i][j]) {
        return Ans[i][j];
    }
    string ans = "";
    if (S[i] == T[j]) {
        ans = string() + S[i] + lcs(i + 1, j + 1);
    }
    else {
        string a = lcs(i + 1, j);
        string b = lcs(i, j + 1);
        if (a.size() < b.size()) {
            ans = b;
        }        
        else if (a.size() > b.size()) {
            ans = a;
        }
        else {
            ans = min(a, b);
        }
    }
    Vs[i][j] = 1;
    return Ans[i][j] = ans;
}

void Try() {
    cin >> S >> T;
    memset(Vs, 0, sizeof Vs);
    if (!lcs(0, 0).empty()) {
        cout << lcs(0, 0) << endl;
    }
    else {
        cout << ":(\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        Try();
    }
    return 0;
} 