#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; ll s; cin >> n >> s;
    int a[n+1];

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int l = 1, r = 1, ans; ll sum = 0; bool got = false;

    while (l <= n && r <= n) {
        sum += a[r++];
        while (sum >= s) {
            ans = min(ans,r-l);
            got = true;
            sum -= a[l++];
        }
    }
    cout << (got ? ans : -1) << endl;
    
    return 0;
} 