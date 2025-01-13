#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,x; cin >> n >> m >> x;
    int a[m+1];
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }

    int fedor; cin >> fedor;
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        int need = a[i] ^ fedor;
        ans += __builtin_popcount(need) <= x;
    }

    cout << ans << endl;
    return 0;
} 