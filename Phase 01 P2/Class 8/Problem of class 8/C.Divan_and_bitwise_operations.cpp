// Created on: 2024-10-17 18:28
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int M = 1e9 + 7;
const int N = 2e5 + 9;
int pow2[N];

void solve()
{
    int n,m; cin >> n >> m;
    int num = 0;
    for (int i = 1; i <= m; i++) {
        int x,y,z; cin >> x >> y >> z;
        num |= z;
    }

    cout << 1LL * pow2[n - 1] * num % M << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    pow2[0] = 1;
    for (int i = 1; i < N; i++) {
        pow2[i] = pow2[i - 1] * 2 % M;
    }
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 