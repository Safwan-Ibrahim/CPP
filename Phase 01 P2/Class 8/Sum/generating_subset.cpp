#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < (1 << n); i++) {
        for (int b = 0; b < 31; b++) {
            if ((i >> b) & 1) {
                cout << a[b] << " ";
            }
        }
        cout << endl;
    }

    return 0;
} 