// Created on: 2025-06-10 06:47
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int zero, one, difference; cin >> zero >> one >> difference;

    bool is_swaped = false;
    if (zero > one) {
        is_swaped = true;
        swap(one, zero);
    }
    
    if (difference < one - zero || difference > one) {
        cout << "-1\n"; return;
    }
    string Ans = "";
    Ans += string(difference, '1');
    for (int i = 1; i <= min(zero, one - difference); i++) {
        Ans += "01";
    }

    Ans += string(abs(zero - (one - difference)), '0');

    for (auto c : Ans) {
        cout << (is_swaped ? char(c ^ 1) : c);
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