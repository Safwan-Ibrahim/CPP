// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    ll k, x; cin >> k >> x;
    ll y = (2LL << k) - x;
    
    vector<int> Ans;
    while(x != y) {
        if (x > y) {
            x -= y;
            y <<= 1;
            Ans.push_back(2);
        }  
        else {
            y -= x;
            x <<= 1;
            Ans.push_back(1);
        }
    }

    reverse(Ans.begin(), Ans.end());
    cout << Ans.size() << endl;
    for (auto x : Ans) {
        cout << x << " ";
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