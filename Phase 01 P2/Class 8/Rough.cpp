#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int x1 = 0,x2 = 0;
    for (int i = 1; i <= 23; i++) {
        if (i & 1) {
            x1 ^= i;
            cout << x1 << endl;
        }
    }
    cout << endl;
    for (int i = 1; i <= 23; i++) {
        if (!(i & 1)) {
            x2 ^= i;
            cout << x2 << endl;
        }
    }

    
    return 0;
} 