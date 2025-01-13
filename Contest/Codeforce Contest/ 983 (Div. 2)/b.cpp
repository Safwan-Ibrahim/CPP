// Created on: 2024-11-02 20:05
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int n,k; cin >> n >> k;
    if (n == 1) {
        cout << 1 << endl;
        cout << 1 << endl;
        return;
    }
    if (k == 1 || k == n) {
        cout << -1 << endl;
        return;
    }
    cout << 3 << endl;
    cout << 1 << " ";
    if (k % 2 == 1) {
        cout << k - 1 << " " << k + 2 << endl;
    }
    else {
        cout << k << " " << k + 1 << endl;
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 