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

    vector<int>cnt(30,0);

    for (int i = 1; i <= n; i++) {
        for (int bt = 0; bt < 30; bt++) {
            if (a[i] >> bt & 1) {
                cnt[bt]++;
            } 
        }
    }

    ll sum = 0;
    for (int i = 0; i < 30; i++) {
        sum += (1LL * cnt[i] << i);
    }

    cout << sum << endl;
    
    return 0;
} 