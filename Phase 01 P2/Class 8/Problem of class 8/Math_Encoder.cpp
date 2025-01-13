// Created on: 2024-10-28 13:59
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e4 + 9;
const int M = 1e9 + 7;
int pow2[N];

void solve(int c)
{   
    cout << "Case #" << c << ": ";
    int n; cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += 1LL * pow2[i - 1] * a[i];
        ans %= M;
        ans -= 1LL * pow2[n - i] * a[i];
        ans %= M;
    }
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    pow2[0] = 1;
    for (int i = 1; i < N; i++) {
        pow2[i] = pow2[i - 1] * 2 % M;
    }
    int c = 0;
    int t = 1; cin >> t;
    while(t--) solve(++c);
    return 0;
} 