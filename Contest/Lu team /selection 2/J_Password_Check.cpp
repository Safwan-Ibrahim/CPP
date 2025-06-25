// Created on: 2025-04-18 14:32
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

string S;

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    bool is_five = false, is_cap = false, is_small = false, is_d = false;
    cin >> S;
    is_five = S.size() >= 5;
    for (auto x : S) {
        if (x >= 'A' && x <= 'Z') {
            is_cap = true;
        }
        if (x >= 'a' && x <= 'z') {
            is_small = true;
        }
        if (x - '0' >= 0 && x - '0' <= 9) {
            is_d = true;
        }
    }    
    if (is_five && is_cap && is_small && is_d) {
        cout << "Correct\n";
    }
    else {
        cout << "Too weak\n";
    }
    return 0;
}