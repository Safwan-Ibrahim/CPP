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

    ll prod = 1;

    for (int i = 1; i <= n; i++) {
        prod *= pow(a[i],2 * n);
    }
    
    return 0;
} 