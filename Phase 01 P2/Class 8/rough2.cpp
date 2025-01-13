#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int a,n; cin >> a >> n;
        int x = 0;
        for (int i = a; i <= n; i++) {
            x ^= i;
            cout << x << endl;
        }
        cout << endl;
    }
    
    return 0;
} 