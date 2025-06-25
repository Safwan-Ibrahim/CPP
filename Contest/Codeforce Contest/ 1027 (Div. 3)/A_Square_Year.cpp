// Created on: 2025-05-26 20:36
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    string S; cin >> S;
    int num = stoi(S);
    int rt = sqrt(num);
    if (rt * rt == num) {
        cout <<  0 << " " << rt << endl;
    }
    else cout << -1 << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 