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
            sum += a[i] + a[j];
        }
    }

    cout << sum << endl;

    // O(n) :
    sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += 2 * n * a[i];
    }

    cout << sum << endl;

    return 0;
} 