#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;    
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // O(n^2)
    ll ans = 0; vector<int>cnt(31,0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans += a[i] ^ a[j];
        }
    }

    // O(n*31)
    for (int i = 1; i <= n; i++) {
        for (int b = 0; b < 31; b++) {
            if ((a[i] >> b) & 1) {
                cnt[b]++;
            }
        }
    }

    cout << ans << endl; 
    ans = 0;
    for (int i = 0; i < 31; i++) {
        ll times = cnt[i] * (n - cnt[i]) * 2;
        ans += (times << i);
    }   

    cout << ans << endl;
    return 0;
} 