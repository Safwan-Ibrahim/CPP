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

    int x = 0;

    for (int i = 1; i <= n; i++) {
        int k = (n-i+1)*i;
        if (k & 1) {
            x ^= a[i];
        } 
    }

    cout << x << endl;
    
    return 0;
} 