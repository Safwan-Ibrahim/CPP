// Created on: 2025-05-20 19:07
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    string S; cin >> S; 
    int n = S.size(); ll pos; cin >> pos;
    S = "#" + S;
    if (pos <= n) {
        cout << S[pos]; return;
    }

    ll total = n; int next = n - 1;
    string Ans = "#";
    for (int i = 1; i <= n; i++) {
        char c = S[i];
        while(Ans.size() > 1 && Ans.back() > c) {
            total += next;
            Ans.pop_back();
            if (pos <= total) {
                for (int j = i; j <= n; j++) {
                    Ans += S[j];
                }
                cout << Ans[pos - (total - next)]; return; 
            }
            next--;
        }
        Ans.push_back(c);
    }

    while(pos > total) {
        total += next;
        Ans.pop_back();
        next--;
    }

    pos -= total - (next + 1);
    cout << Ans[pos];

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 