#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int M = 1e9 + 7;

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int a[n + 1], b[n + 1], fact[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = 1LL * fact[i - 1] * i % M;
    }
    
    vector<int>cnt_a(20,0) , cnt_b(20,0);
    for (int i = 1; i <= n; i++) {
        for (int k = 0; k < 20; k++) {
            cnt_b[k] += (b[i] >> k) & 1;
            cnt_a[k] += (a[i] >> k) & 1;
        }
    }

    int pow2[20];
    pow2[0] = 1;
    for (int i = 1; i < 20; i++) {
        pow2[i] = pow2[i - 1] * 2 % M;
    }

    ll ans = 0;
    for (int i = 0; i < 20; i++) {
        ll con = 1LL * cnt_a[i] * (n - cnt_b[i]) % M;
        con += 1LL * cnt_b[i] * (n - cnt_a[i]) % M;
        con *= fact[n - 1];
        con %= M;
        ans += 1LL * pow2[i] * con % M;
        ans %= M;
    }

    cout << ans << endl;

    return 0;
} 