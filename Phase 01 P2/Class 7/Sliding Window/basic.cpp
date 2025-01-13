#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k; cin >> n >> k;
    int a[n+1];

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
        if (i >= k) {
            cout << sum << " ";
            sum -= a[i-k+1];
        }
    }

    return 0;
} 