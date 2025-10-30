// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    string S; cin >> S;
    
    vector<int> A;
    int i = 1;
    for (auto c : S) {
        if (c == '0') {
            A.push_back(i);
        }
        i++;
    }

    cout << A.size() << endl;
    for (auto x : A) cout << x << " ";
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