#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; ll s; cin >> n >>s;
    int a[n+1];

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int r = 1; ll sum = 0, ans = 0;

    for  (int l = 1; l <= n; l++) {
        while (sum + a[r] < s && r <= n) {
            sum += a[r++];
        }
        ans += r-l;
        sum -= a[l];
    }

    cout << 1LL*n*(n+1)/2-ans << endl;

    return 0;
} 