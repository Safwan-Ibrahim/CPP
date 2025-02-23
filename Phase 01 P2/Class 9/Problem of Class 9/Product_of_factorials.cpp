#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const ll M = 109546051211;
const int N = 1e7 + 9;

ll fact[N];

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (__int128) fact[i - 1] * i % M;
    }

    int n; cin >> n;

    ll ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = (__int128) fact[i] * ans % M;
    }

    cout << ans << endl;
    
    return 0;
} 