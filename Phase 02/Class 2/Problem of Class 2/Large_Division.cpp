// Created on: 2025-01-07 19:51
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(int t) {
    string a; int b; cin >> a >> b;
    
    int num = 0; bool minus = false;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '-') {
            minus = true;
        }
        else {
            int d = a[i] - '0';
            num = (1LL * 10 * num + d) % b;
        }
    }
    if (minus) {
        num = (1LL * num + b) % b;
    }

    cout << "Case " << t << ": " << (num == 0 ? "divisible" : "not divisible") << endl;
    return;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t = 1; cin >> t; int c = 1;
    while(t--) solve(c++);
    return 0;
} 