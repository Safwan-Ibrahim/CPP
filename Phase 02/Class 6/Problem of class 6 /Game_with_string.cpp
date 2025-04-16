// Created on: 2025-04-13 15:15
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    string S; cin >> S;
    stack<char>St;
    int cnt = 0;
    for (int i = 0; i < S.size(); i++) {
        if (!St.empty() && S[i] == St.top()) {
            cnt++;
            St.pop();
        }
        else {
            St.push(S[i]);
        }
    }

    cout << (cnt % 2 ? "YES\n" : "NO\n");

    return 0;
} 