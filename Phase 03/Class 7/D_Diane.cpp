// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;

    if (n == 1) {
        cout << 'x' << endl; return;
    }
    string Ans(n / 2, 'a');
    Ans += (n & 1 ? "bc" : "b");
    Ans += string(n - (n / 2 + 1 + n % 2), 'a');
    cout << Ans << endl;
    assert(Ans.size() == n);
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 