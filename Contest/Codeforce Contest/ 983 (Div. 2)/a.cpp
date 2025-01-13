// Created on: 2024-11-02 19:15
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int n; cin >> n;
    int cnt1 = 0, cnt0 = 0;
    for (int i = 1; i <= 2 * n; i++) {
        int a; cin >> a;
        if (a) {
            cnt1++;
        }
        else {
            cnt0++;
        }
    }
    cout << cnt0 % 2 << " ";
    cout << min(cnt0,cnt1) << endl;
    
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 