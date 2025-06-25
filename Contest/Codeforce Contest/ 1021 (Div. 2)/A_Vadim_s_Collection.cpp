// Created on: 2025-04-26 14:38
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    string S; cin >> S;
    for (int i = 0; i < S.size(); i++) {
        int d = S[i] - '0';
        int id = i;
        for (int j = i + 1; j < S.size(); j++) {
            int e = S[j] - '0';
            //cerr << d << " " << e << endl;
            if (e < d && e >= 10 - i - 1) {
                d = e;
                id = j;
            }
        }
        swap(S[i], S[id]);
    }

    cout << S << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 