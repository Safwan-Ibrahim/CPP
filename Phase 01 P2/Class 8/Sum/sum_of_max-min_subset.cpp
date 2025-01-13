#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int a[n+1];

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    sort (a + 1, a + n + 1);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            ans += (a[j] - a[i]) * (1 << (j - i - 1)); 
        }
    }

    cout << ans << endl;
    ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += a[i] * (1 << (i - 1));
        ans -= a[i] * (1 << (n - i));
    }

    cout << ans << endl;
    return 0;
} 