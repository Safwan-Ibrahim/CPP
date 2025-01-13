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

    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sum += a[i] | a[j];
        }
    }

    cout << sum << endl; sum = 0;
    vector<int>cnt(31,0);

    for (int i = 1; i <= n; i++) {
        for (int b = 0; b < 31; b++) {
            if (!(a[i] >> b & 1)) {
                cnt[b]++;
            }
        }
    }

    for (int b = 0; b < 31; b++) {
        ll con = n * n - cnt[b] * cnt[b];
        sum += (con << b);
    }

    cout << sum << endl;
    
    return 0;
} 