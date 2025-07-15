// Created on: 2025-07-06 17:34
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int min_step(string &S) {
    int n = S.size();
    string Tmp;
    for (int i = 1; i < n; i++) {
        Tmp = S.substr(i, n - i + 1) + S.substr(0, i);
        if (Tmp == S) return i;
    }
    return n;
}

void Try() {
    int n; cin >> n; 
    string S; cin >> S; 
    S = "#" + S;
    int A[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    vector<string>V;
    vector<bool>Vs(n + 1, false);
    for (int i = 1; i <= n; i++) {
        string Tmp = "";
        int x = i;
        while(Vs[x] == false) {
            Tmp += S[x]; Vs[x] = true;
            x = A[x];
        }
        if (Tmp.size()) V.push_back(Tmp);
    }

    ll lcm_ = 1;
    for (auto st : V) {
        int ln = min_step(st);
        lcm_ = lcm(lcm_, ln);

    }
    cout << lcm_ << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 