// Created on: 2025-09-23 01:29
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    vector<string> v = {"st", "nd", "rd", "th"};
    for (int i = 1; i <= 31; i++) {
        int l = i % 10, sl = i / 10 % 10;
        cout << i << (sl == 1 || l == 0 ? v[3] : v[min(3, l - 1)]) << endl;
    }

    return 0;
} 