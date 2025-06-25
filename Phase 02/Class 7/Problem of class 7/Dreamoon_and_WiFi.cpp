// Created on: 2025-04-17 03:21
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

string S, T;

int pos, total, position;
void go(int i) {
    if (i == T.size()) {
        total++;
        int p = 0;
        for (auto x : T) {
            if (x == '+') {
                p++;
            }
            else {
                p--;
            }
        }
        if (p == position) {
            pos++;
        }
        return;
    }
    if (T[i] == '?') {
        T[i] = '+';
        go(i + 1);
        T[i] = '-';
        go(i + 1);
        T[i] = '?';
    }
    else {
        go(i + 1);
    }
    return;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> S >> T;
    for (auto x : S) {
        if (x == '+') {
            position++;
        }
        else {
            position--;
        }
    }
    go(0);

    double ans = (double) pos / total;
    cout << fixed << setprecision(12) << ans << endl;
    
    return 0;
} 