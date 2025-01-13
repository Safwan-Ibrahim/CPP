#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5 + 9, M = 1e9 + 7;
int pow2[N];

void go(int n) {
    pow2[0] = 1;
    for (int i = 1; i <= n; i++) {
        pow2[i] = pow2[i - 1] * 2 % M;
    }

}

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << 0 << endl; return 0;
    }

    
    go(n - 2);
    sort(a + 1, a + n + 1,greater<>());
    ll ans = 0;
    int m = n - 2;
    for (int i = 1; i <= n; i++) {
        // ans = (ans + 1LL * pow2[n - 2] * a[i] * (n - i) % M) % M;
        // ans = ((ans - 1LL * pow2[n - 2] * a[i] * (i - 1) % M) + M) % M;
        ans += 1LL * ((n - (2 * i) + 1) + M) % M * a[i];
        ans %= M;
    }

    cout << 1LL * ans * pow2[n - 2] % M << endl;
    return 0;
} 