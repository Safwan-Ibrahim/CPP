// Created on: 2024-10-24 21:46
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 2e5 + 9;
int n,a[N];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = n / 2, j = n / 2 + 1 + (n & 1); i >= 1; i--,j++) {
        if (a[i] == a[i + 1] || a[j] == a[j - 1]) {
            swap(a[i],a[j]);
        }
    }

    int cnt = 0;
    for (int i = 1; i < n; i++) {
        cnt += a[i] == a[i + 1];
    }
    cout << cnt << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 