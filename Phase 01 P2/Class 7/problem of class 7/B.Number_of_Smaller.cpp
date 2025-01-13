#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin >> n >> m;
    int a[n+1],b[m+1];

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    int p = 1;

    for (int i = 1; i <= m; i++) {
        while (a[p] < b[i] and p <= n) {
            p++;
        }
        cout << p-1 << " ";
    }

    cout << endl;

    return 0;
} 