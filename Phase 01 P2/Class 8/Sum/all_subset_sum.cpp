#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main()
{   
    int n; cin >> n;
    int a[n + 1];

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ll sum = 0;

    for (int i = 1; i <= n; i++) {
        sum += a[i] * (1 << (n - 1)) << endl;
    }
    
    return 0;
} 