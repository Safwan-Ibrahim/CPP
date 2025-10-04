// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int d; cin >> d;

    vector<int> Ans;
    while(d > 100000) {
        Ans.insert(Ans.end(), {100000, 100000 - 1, 1, 3, 2, 1, 3, 2, 1});
        d -= 100000;
    }
    
    if (d <= 3) {
        for (int i = 1; i <= d; i++) {
            Ans.insert(Ans.end(), {3, 2, 1});
        }
    }
    else {
        Ans.insert(Ans.end(), {d, d - 1, 1, 3, 2, 1, 3, 2, 1});
    }

    cout << Ans.size() << endl;
    for (auto x : Ans) cout << x << " ";
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