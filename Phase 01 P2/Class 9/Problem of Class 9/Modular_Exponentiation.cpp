#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    if (n < 31) {
        cout << m % (1 << n) << endl;
    }
    else {
        cout << m << endl;
    }
    
    return 0;
} 