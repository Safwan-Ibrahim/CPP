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

    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            for (int k = i; k <= j; k++) {
                sum += a[k];
            }
        }
    }

    cout << sum << endl;

    sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i] * (n-i+1) * i;
    }
    
    cout << sum << endl;
    
    return 0;
} 