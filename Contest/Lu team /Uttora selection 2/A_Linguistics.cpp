// Created on: 2025-06-02 16:23
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    string S;
    int a, b, ab, ba; cin >> a >> b >> ab >> ba;
    cin >> S;
    string Need = "";
    for (int i = 0; i < S.size(); i++) {
        if (i == 0 && i == S.size() - 1) {
            Need += S[i];
        } 
        else if (i == S.size() - 1) Need += S[i];
        else if (i == 0) {
            if (S[i] == S[i + 1]) {
                if (S[i] == 'A') a--;
                else b--;
            }
        }
        else if (S[i - 1] == S[i] && S[i] == S[i + 1]) {
            if (S[i] == 'A') a--;
            else b--;
        }
        else Need += S[i];
    }
    
    for (int i = 0; i < Need.size() - 1; i += 2) {
        if (Need[i] == 'A' && Need[i + 1] == 'B') {
            ab--;
        }
        else ba--;
    }

    if (0 - ba > 0) {
        a -= -ba;
        b -= -ba;
    } 
    if (0 - ab > 0) {
        a -= -ab;
        b -= -ab;
    }

    if (a >= 0 && b >= 0) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
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